#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <iostream>
#include "game_grid.h"

#ifdef _OPENMP

#include <omp.h>

#endif

namespace cgol {
    using StrategyT =
    std::function<const cgol::StepsHistorySharedPtrT(
            const cgol::GameGridSharedPtrT &inputGrid,
            size_t steps)>;


    void calculateStep(const GameGridSharedPtrT &prev, GameGridSharedPtrT &next,
                       size_t row, size_t col);

    const cgol::StepsHistorySharedPtrT
    strategyCPU(const cgol::GameGridSharedPtrT &inputGrid, size_t steps);
}


#endif
