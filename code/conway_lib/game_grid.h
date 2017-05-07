#ifndef GAME_GRID_H
#define GAME_GRID_H

#include <memory>
#include <vector>
#include <random>

namespace cgol {

    const size_t GRID_MAX_WIDTH = 128;
    const size_t GRID_MAX_HEIGHT = 128;
    using GridRawEntries = std::vector<int>;

    class GameGrid {
    public:
        GameGrid(size_t gridWidth, size_t gridHeight, bool randomize=true);

        GameGrid(const GridRawEntries& rawEntries, size_t gridWidth, size_t gridHeight);
        GameGrid(const GameGrid& grid);

        int getEntry(size_t row, size_t col);

        size_t getWidth() const;

        size_t getHeight() const;

        GridRawEntries getRawEntries() const;

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
