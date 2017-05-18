#ifndef CONWAY_H
#define CONWAY_H

#include <iostream>
#include "game_grid.h"
#include "array"
#include "strategies.h"


namespace cgol {

    class ConwaysGameOfLife {
    public:
        ConwaysGameOfLife(GameGridSharedPtrT &inputGrid);

        const cgol::StepsHistorySharedPtrT
        run(const StrategyT &strategy, int steps);

    private:
        GameGridSharedPtrT m_inputGrid;
    };

    using GameSharedPtrT = std::shared_ptr<ConwaysGameOfLife>;
}


#endif
