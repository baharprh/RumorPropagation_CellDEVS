#ifndef CADMIUM_CELLDEVS_RUMOR_COUPLED_HPP
#define CADMIUM_CELLDEVS_RUMOR_COUPLED_HPP

#include <memory>
#include <string>

#include <cadmium/modeling/celldevs/grid/coupled.hpp>
#include "rumorCell.hpp"

using namespace cadmium::celldevs;

template<typename S, typename V>
std::shared_ptr<GridCell<S, V>> rumorCellFactory(
    const coordinates& cellId,
    const std::shared_ptr<const GridCellConfig<S, V>>& config
) {
    return std::make_shared<rumorCell<S, V>>(cellId, config);
}

template<typename S, typename V>
class rumor_coupled : public GridCellDEVSCoupled<S, V> {
public:
    rumor_coupled(const std::string& id, const std::string& config_file)
        : GridCellDEVSCoupled<S, V>(id, &rumorCellFactory<S, V>, config_file) {}
};

#endif