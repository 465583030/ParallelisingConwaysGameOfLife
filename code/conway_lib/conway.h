#ifndef CONWAY_H
#define CONWAY_H

#include <iostream>
#include "typedefs.h"

#ifdef _OPENMP
    #include <omp.h>
#endif

namespace cgl {

    class ConwaysGameOfLife {
    public:
        ConwaysGameOfLife(size_t gridWidth  = GRID_MAX_WIDTH,
                          size_t gridHeight = GRID_MAX_HEIGHT);

    private:
        grid_t m_grid;
        grid_t m_swapGrid;
        gridsAccumulator_t m_results;
    };
}


#endif
