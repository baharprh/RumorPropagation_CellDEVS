#include <iostream>
#include <memory>
#include <string>

#include <cadmium/simulation/root_coordinator.hpp>
#include <cadmium/core/logger/csv.hpp>
#include "rumor_coupled.hpp"

using namespace cadmium;
using namespace cadmium::celldevs;

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: ./rumor_sim <config.json>\n";
        return 0;
    }

    std::string config = argv[1];

    auto model = std::make_shared<rumor_coupled<rumorState, int>>("rumor", config);

    RootCoordinator rootCoordinator(model);

    auto logger = std::make_shared<cadmium::CSVLogger>("bin/messages.csv", ";");
    rootCoordinator.setLogger(logger);

    rootCoordinator.start();
    rootCoordinator.simulate(1000.0);
    rootCoordinator.stop();

    return 0;
}
