// Board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Cell.hpp"
#include <vector>
#include <random>

class Board {
    std::vector<std::vector<Cell>> grid;
    int width, height;

public:
    Board(int width, int height) : width(width), height(height), grid(width, std::vector<Cell>(height)) {}

    void placeMines(int mineCount);
    void revealCell(int x, int y);
    void toggleFlag(int x, int y);
};

#endif 

//2d array 
//each cell is a Cell class
//3 levels:
//1. beginner (9x9 board with 10 mines)
//2. intermediate (16x16 board with 40 mines)
//3. advanced (24x24 board with 99 mines)
