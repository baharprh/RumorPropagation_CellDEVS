#include <fstream>
#include <cadmium/modeling/dynamic_coupled.hpp>
#include <cadmium/engine/pdevs_dynamic_runner.hpp>
#include <cadmium/logger/common_loggers.hpp>
#include "rumor_coupled.hpp"

using namespace std;
using namespace cadmium;
using namespace cadmium::celldevs;

using TIME = double;

/*************** Loggers *******************/
static ofstream out_messages("../logs/output_messages.txt");
struct oss_sink_messages {
    static ostream& sink() {
        return out_messages;
    }
};

static ofstream out_state("../logs/state.txt");
struct oss_sink_state {
    static ostream& sink() {
        return out_state;
    }
};

using state_logger = logger::logger<logger::logger_state, logger::formatter<TIME>, oss_sink_state>;
using log_messages = logger::logger<logger::logger_messages, logger::formatter<TIME>, oss_sink_messages>;
using global_time_messages = logger::logger<logger::logger_global_time, logger::formatter<TIME>, oss_sink_messages>;
using global_time_state = logger::logger<logger::logger_global_time, logger::formatter<TIME>, oss_sink_state>;

using logger_top = logger::multilogger<
    state_logger,
    log_messages,
    global_time_messages,
    global_time_state
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
    float sim_time = (argc > 2) ? static_cast<float>(atof(argv[2])) : 50.0f;
    r.turn_progress_on();
    r.run_until(sim_time);

    return 0;
}
