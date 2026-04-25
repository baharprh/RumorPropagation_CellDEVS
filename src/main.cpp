#include <iostream>
#include <memory>
#include <string>

#include <cadmium/simulation/root_coordinator.hpp>
#include "rumor_coupled.hpp"

using namespace cadmium;
using namespace cadmium::celldevs;

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: ./rumor_sim <config.json> [MAX_TIME]\n";
        return 0;
    }

    std::string config = argv[1];

    double max_time = 1000.0;
    if (argc >= 3) {
        max_time = std::stod(argv[2]);
    }

    auto model = std::make_shared<rumor_coupled<rumorState, int>>("rumor", config);

    RootCoordinator rootCoordinator(model);

    rootCoordinator.start();
    rootCoordinator.simulate(max_time);
    rootCoordinator.stop();

    return 0;
}