#ifndef CADMIUM_CELLDEVS_RUMOR_CELL_HPP
#define CADMIUM_CELLDEVS_RUMOR_CELL_HPP

#include <cadmium/celldevs/cell/grid_cell.hpp>

using namespace cadmium::celldevs;

template <typename T>
class rumor_cell : public grid_cell<T, int, int> {
public:
    using grid_cell<T, int, int>::simulation_clock;
    using grid_cell<T, int, int>::state;
    using grid_cell<T, int, int>::map;
    using grid_cell<T, int, int>::neighbors;

    int spreading_time;

    rumor_cell() : grid_cell<T, int, int>(), spreading_time(1) {}

    rumor_cell(
        cell_position const &cell_id,
        cell_unordered<int> const &neighborhood,
        int initial_state,
        cell_map<int, int> const &map_in,
        std::string const &delay_id,
        int config
    ) : grid_cell<T, int, int>(cell_id, neighborhood, initial_state, map_in, delay_id),
        spreading_time(config) {}

    int local_computation() const override {
        int current = state.current_state;

        // 2 = inactive stays inactive
        if (current == 2) {
            return 2;
        }

        // 1 = spreading becomes inactive
        if (current == 1) {
            return 2;
        }

        // 0 = unaware becomes spreading if any neighbor is spreading
        if (current == 0) {
            for (auto neighbor : neighbors) {
                if (state.neighbors_state.at(neighbor) == 1) {
                    return 1;
                }
            }
            return 0;
        }

        return current;
    }

    T output_delay(int const &cell_state) const override {
        return T(1);
    }
};

#endif
