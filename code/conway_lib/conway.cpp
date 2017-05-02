#include "conway.h"

cgl::ConwaysGameOfLife::ConwaysGameOfLife(size_t gridWidth, size_t gridHeight) {

    // Check input arguments
    if (gridWidth > GRID_MAX_WIDTH || gridHeight > GRID_MAX_HEIGHT) {
        throw std::logic_error(
                "Wrong grid's dimensions. Width's interval is <0, " +
                std::to_string(GRID_MAX_WIDTH) +
                ">. Height's interval is <0, " +
                std::to_string(GRID_MAX_HEIGHT) + ">.");
    }

    // Reserve space in memory for speedup
    size_t gridArea = gridWidth * gridHeight;
    m_grid.reserve(gridArea);
    m_swapGrid.reserve(gridArea);

    // Fill grids with blanks
    for (size_t i = 0; i < gridArea; ++i) {
        m_grid.push_back(false);
        m_swapGrid.push_back(false);
    }

}
