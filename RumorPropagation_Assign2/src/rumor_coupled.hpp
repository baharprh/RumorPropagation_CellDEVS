#ifndef CADMIUM_CELLDEVS_RUMOR_COUPLED_HPP
#define CADMIUM_CELLDEVS_RUMOR_COUPLED_HPP

#include <cadmium/celldevs/coupled/grid_coupled.hpp>
#include "rumorCell.hpp"

template <typename T>
class rumor_coupled : public cadmium::celldevs::grid_coupled<T, int, int> {
public:
    using base_type = cadmium::celldevs::grid_coupled<T, int, int>;
    using cell_map_type = typename cadmium::celldevs::cell_map<int, int>;

    explicit rumor_coupled(const std::string& id) : base_type(id) {}

    void add_grid_cell_json(
        const std::string& cell_type,
        cell_map_type& map,
        const std::string& delay_id,
        const cadmium::json& config
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
