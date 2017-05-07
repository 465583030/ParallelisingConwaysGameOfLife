#include "game_grid.h"

cgol::GameGrid::GameGrid(size_t gridWidth, size_t gridHeight, bool randomize)
        : m_width(gridWidth), m_height(gridHeight) {

    // Check input arguments
    checkGridDimensions(gridWidth, gridHeight);

    // Reserve space in memory for speedup
    size_t gridArea = gridWidth * gridHeight;
    m_entries.reserve(gridArea);

    // Fill grid with random entries
    // TODO: make more transparent
    if(randomize) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);
        for (size_t i = 0; i < gridArea; ++i) {
            m_entries.push_back(dis(gen));
        }
    } else {
        for (size_t i = 0; i < gridArea; ++i) {
            m_entries.push_back(0);
        }
    }

}


cgol::GameGrid::GameGrid(const cgol::GridRawEntries &rawEntries,
                         size_t gridWidth, size_t gridHeight)
        : m_width(gridWidth), m_height(gridHeight) {

    checkGridDimensions(gridWidth, gridHeight);
    if (rawEntries.size() / gridWidth != gridHeight ||
        rawEntries.size() / gridHeight != gridWidth) {
        throw std::runtime_error("Error: raw entry data has wrong dimensions");
    }

    m_entries = rawEntries;
}

size_t cgol::GameGrid::getWidth() const {
    return m_width;
}

size_t cgol::GameGrid::getHeight() const {
    return m_height;
}

void cgol::GameGrid::checkGridDimensions(size_t gridWidth, size_t gridHeight) {
    if (gridWidth > GRID_MAX_WIDTH || gridHeight > GRID_MAX_HEIGHT) {
        throw std::logic_error(
                "Wrong grid's dimensions. Width's interval is <0, " +
                std::to_string(GRID_MAX_WIDTH) +
                ">. Height's interval is <0, " +
                std::to_string(GRID_MAX_HEIGHT) + ">.");
    }
}

GridRawEntries cgol::GameGrid::getRawEntries() const {
    return m_entries;
}

int cgol::GameGrid::getEntry(size_t row, size_t col) {
    if (row < 0 || row > m_height || col < 0 || col > m_width) {
        return 0;
    } else {
        size_t index = row * m_height + col;
        return m_entries[index];
    }

}

cgol::GameGrid::GameGrid(const cgol::GameGrid &grid) :
        m_width(grid.getWidth()), m_height(grid.getHeight()) {
    m_entries = grid.getRawEntries();
}


