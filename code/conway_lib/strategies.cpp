#include "strategies.h"

void
cgol::calculateStep(const GameGridSharedPtrT &prev, GameGridSharedPtrT &next,
                    size_t row, size_t col) {

    int aliveNeighbours = 0;
    aliveNeighbours += prev->getEntry(row - 1, col);
    aliveNeighbours += prev->getEntry(row + 1, col);
    aliveNeighbours += prev->getEntry(row - 1, col - 1);
    aliveNeighbours += prev->getEntry(row + 1, col + 1);
    aliveNeighbours += prev->getEntry(row, col - 1);
    aliveNeighbours += prev->getEntry(row, col + 1);
    aliveNeighbours += prev->getEntry(row - 1, col + 1);
    aliveNeighbours += prev->getEntry(row + 1, col + 1);


}

const cgol::StepsHistorySharedPtrT
cgol::strategyCPU(const cgol::GameGridSharedPtrT &inputGrid,
                  size_t steps) {
    cgol::StepsHistorySharedPtrT stepsHistory;

    for (size_t i = 0; i < steps; ++i) {
        // Create a grid for next step
        GameGridSharedPtrT nextStep = std::make_shared<GameGrid>(
                inputGrid->getWidth(), inputGrid->getHeight(), false);

        // Update next step grid
        for (size_t row = 0; row < inputGrid->getHeight(); ++row) {
            for (size_t col = 0; col < inputGrid->getWidth(); ++col) {
                calculateStep(inputGrid, nextStep, row, col);

            }
        }

        // Save next step
        stepsHistory.push_back(nextStep);
    }

    return stepsHistory;
}
