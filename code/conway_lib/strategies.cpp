#include "strategies.h"

void
cgol::calculateStep(const GameGridSharedPtrT &prev, GameGridSharedPtrT &next,
                    int row, int col) {

    int aliveNeighbours = 0;
    aliveNeighbours += prev->getEntry(row - 1, col);
    aliveNeighbours += prev->getEntry(row + 1, col);
    aliveNeighbours += prev->getEntry(row - 1, col - 1);
    aliveNeighbours += prev->getEntry(row + 1, col + 1);
    aliveNeighbours += prev->getEntry(row, col - 1);
    aliveNeighbours += prev->getEntry(row, col + 1);
    aliveNeighbours += prev->getEntry(row - 1, col + 1);
    aliveNeighbours += prev->getEntry(row + 1, col - 1);

    bool isCellAlive = (prev->getEntry(row, col) == 1);
    std::cout << "isCellAlive: " << isCellAlive << " aliveNeighbours: " << aliveNeighbours << std::endl;
    if (isCellAlive && (aliveNeighbours < 2 || aliveNeighbours > 3)) {
        next->setEntry(row, col, 0);
    }
    else if(!isCellAlive && aliveNeighbours == 3) {
        next->setEntry(row, col, 1);
    }
}

const cgol::StepsHistorySharedPtrT
cgol::strategyCPU(const cgol::GameGridSharedPtrT &inputGrid,
                  int steps) {


    cgol::StepsHistorySharedPtrT stepsHistory;
    std::cout << "step 0\n";
    inputGrid->print();

    for (int i = 0; i < steps; ++i) {
        // Create a grid for next step
        GameGridSharedPtrT nextStep = std::make_shared<GameGrid>(
                inputGrid->getWidth(), inputGrid->getHeight(), false);
        std::cout << " step " << i+1 << std::endl;
        // Update next step grid
        for (int row = 0; row < inputGrid->getHeight(); ++row) {
            for (int col = 0; col < inputGrid->getWidth(); ++col) {
                calculateStep(inputGrid, nextStep, row, col);
            }
        }
        // Temp debug

        nextStep->print();

        // Save next step
        stepsHistory.push_back(nextStep);
    }

    return stepsHistory;
}
