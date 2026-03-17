#include <fstream>
#include <vector>
#include <cadmium/modeling/dynamic_coupled.hpp>
#include <cadmium/engine/pdevs_dynamic_runner.hpp>
#include <cadmium/logger/common_loggers.hpp>
#include <web/web_logger.hpp>
#include <web/web_results.hpp>
#include "rumor_coupled.hpp"

using namespace std;
using namespace cadmium;
using namespace cadmium::celldevs;

using TIME = double;

/*************** Log files *******************/
static ofstream out_messages("../viewer/output_messages.txt");
struct oss_sink_messages {
    static ostream& sink() {
        return out_messages;
    }
};

static ofstream out_state("../viewer/state_messages.txt");
struct oss_sink_state {
    static ostream& sink() {
        return out_state;
    }
};

/*************** Web-format loggers *******************/
using web_state = cadmium::web::logger<
    cadmium::logger::logger_state,
    cadmium::web::formatter<TIME>,
    oss_sink_state
>;

using web_log_messages = cadmium::web::logger<
    cadmium::logger::logger_messages,
    cadmium::web::formatter<TIME>,
    oss_sink_messages
>;

using web_global_time_mes = cadmium::web::logger<
    cadmium::logger::logger_global_time,
    cadmium::web::formatter<TIME>,
    oss_sink_messages
>;

using web_global_time_sta = cadmium::web::logger<
    cadmium::logger::logger_global_time,
    cadmium::web::formatter<TIME>,
    oss_sink_state
>;

using logger_top = cadmium::logger::multilogger<
    web_state,
    web_log_messages,
    web_global_time_mes,
    web_global_time_sta
>;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Program used with wrong parameters. Use:" << endl;
        cout << argv[0] << " RUMOR_CONFIG.json [MAX_SIMULATION_TIME]" << endl;
        return -1;
    }

    rumor_coupled<TIME> test = rumor_coupled<TIME>("rumor");
    std::string scenario_config_file_path = argv[1];
    test.add_lattice_json(scenario_config_file_path);
    test.couple_cells();

    std::shared_ptr<cadmium::dynamic::modeling::coupled<TIME>> t =
        std::make_shared<rumor_coupled<TIME>>(test);

    cadmium::dynamic::engine::runner<TIME, logger_top> r(t, {0});
    float sim_time = (argc > 2) ? atof(argv[2]) : 50;
    r.turn_progress_on();
    r.run_until(sim_time);

    std::vector<std::string> fields = {"state"};
    cadmium::web::convert_cell_devs(
        fields,
        scenario_config_file_path,
        "../viewer/state_messages.txt",
        "../viewer/"
    );

    return 0;
}
