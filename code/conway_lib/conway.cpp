#include "conway.h"

cgol::ConwaysGameOfLife::ConwaysGameOfLife(GameGridSharedPtrT &inputGrid) {
    if(inputGrid.get() == nullptr) {
        throw std::runtime_error("Error: input grid is nullptr");
    }
    m_inputGrid = inputGrid;
}

const cgol::StepsHistorySharedPtrT
cgol::ConwaysGameOfLife::run(const cgol::StrategyT &strategy, size_t steps) {
    return strategy(m_inputGrid, steps);
}
