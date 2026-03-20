#ifndef CADMIUM_CELLDEVS_RUMOR_CELL_HPP
#define CADMIUM_CELLDEVS_RUMOR_CELL_HPP

#include <cadmium/modeling/celldevs/grid/cell.hpp>
#include <nlohmann/json.hpp>
#include <iostream>
#include <memory>
#include <unordered_map>

using namespace cadmium::celldevs;

struct rumorState {
    int state;
    rumorState() : state(0) {}
};

inline std::ostream& operator<<(std::ostream& os, const rumorState& x) {
    os << "<" << x.state << ">";
    return os;
}

inline bool operator!=(const rumorState& x, const rumorState& y) {
    return x.state != y.state;
}

inline void from_json(const nlohmann::json& j, rumorState& s) {
    j.at("state").get_to(s.state);
}

template<typename S, typename V>
class rumorCell : public GridCell<S, V> {
public:
    rumorCell(
        const coordinates& id,
        const std::shared_ptr<const GridCellConfig<S, V>>& config
    ) : GridCell<S, V>(id, config) {}

    S localComputation(
     S state,
    const std::unordered_map<coordinates, NeighborData<S, V>>& neighborhood
) const override {
    for (const auto& [coord, neighbor] : neighborhood) {
        if (neighbor.state != nullptr && neighbor.state->state == 1) {
            state.state = 1;
        }
    }
    return state;
}

    double outputDelay(const S& state) const override {
        return 1.0;
    }
};

#endif