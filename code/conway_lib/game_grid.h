#ifndef GAME_GRID_H
#define GAME_GRID_H

#include <iostream>
#include <memory>
#include <vector>
#include <random>


#include "utilities.h"

namespace cgol {

    const size_t GRID_MAX_WIDTH = 128;
    const size_t GRID_MAX_HEIGHT = 128;
    using GridRawEntries = std::vector<int>;

    class GameGrid {
    public:
        GameGrid(size_t gridWidth, size_t gridHeight, bool randomize = true);

        GameGrid(const GridRawEntries &rawEntries, size_t gridWidth,
                 size_t gridHeight);

        GameGrid(const GameGrid &grid);

        // In case of accessing value from invalid row/ col - 0 will be
        // returned.
        int getEntry(int row, int col);

        void setEntry(int row, int col, int value);

        size_t getWidth() const;

        size_t getHeight() const;

        GridRawEntries getRawEntries() const;

        void print();

    private:
        void checkGridDimensions(size_t gridWidth, size_t gridHeight);

        GridRawEntries m_entries;
        const size_t m_width;
        const size_t m_height;
    };

    using GameGridSharedPtrT = std::shared_ptr<GameGrid>;
    using StepsHistorySharedPtrT = std::vector<GameGridSharedPtrT>;
}

#endif
