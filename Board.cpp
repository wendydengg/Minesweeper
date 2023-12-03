// Board.cpp
#include "Board.hpp"
#include <iostream>

Board::Board(int w, int h) : width(w), height(h), grid(w, std::vector<std::unique_ptr<Cell>>(h)) {
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            grid[x][y] = std::make_unique<Cell>();
        }
    }
}

void Board::placeMines(int mineCount) {
    // Randomly place mines

}

void Board::revealCell(int x, int y) {
    // Reveal a cell and adjacent cells if necessary
}

void Board::toggleFlag(int x, int y) {
    // Toggle a flag or a question mark on a cell
}

void Board::displayBoard() const {
    // Display the board on the console
}

bool Board::isGameWon() const {
    // Check if the game is won
}
