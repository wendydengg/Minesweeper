// Board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Cell.hpp"
#include <vector>
#include <memory>

template<typename T>
class Board {
public:
    Board(int w, int h, int mineCount);
    void placeMines();
    void revealCell(int x, int y);
    void toggleFlag(int x, int y);
    void displayBoard() const;
    bool isGameWon() const;
    std::pair<int, int> getHint();

private:
    int width;
    int height;
    int remainingUnopenedCells;
    std::vector<std::vector<std::unique_ptr<T>>> grid;

    bool isValidCell(int x, int y) const;
};

#endif


//2d array 
//each cell is a Cell class
//* use unique pointers
//3 levels:
//1. beginner (9x9 board with 10 mines)
//2. intermediate (16x16 board with 40 mines)
//3. advanced (24x24 board with 99 mines)
