#ifndef CADMIUM_CELLDEVS_RUMOR_COUPLED_HPP
#define CADMIUM_CELLDEVS_RUMOR_COUPLED_HPP

#include <cadmium/celldevs/coupled/grid_coupled.hpp>
#include "rumorCell.hpp"

template <typename T>
class rumor_coupled : public cadmium::celldevs::grid_coupled<T, int, int> {
public:
    explicit rumor_coupled(std::string const &id) : grid_coupled<T, int, int>(id) {}

    void add_grid_cell_json(
        std::string const &cell_type,
        cell_map<int, int> &map,
        std::string const &delay_id,
        cadmium::json const &config
    ) override {
        if (cell_type == "rumor") {
            int conf = config.get<int>();
            this->template add_cell<rumor_cell>(map, delay_id, conf);
        } else {
            throw std::bad_typeid();
        }
    }
};

#endif
