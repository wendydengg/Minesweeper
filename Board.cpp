// Board.cpp
#include "Board.hpp"
#include <iostream>

Board::Board(int w, int h, int mineCount, int num, const std::string& level) : width(w), height(h), level(level),
                                            remainingUnopenedCells(w * h), grid(w, std::vector<std::unique_ptr<Cell>>(h)) {
    // change input to difficluty 
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            grid[x][y] = std::make_unique<Cell>();
        }
    }
}

void Board::placeMines() {
    // Seed for randomization
    std::srand(std::time(0));

    int minesToPlace = 0;

    if (level == "beginner") {
        minesToPlace = 10;
    }
    else if (level == "intermediate") {
        minesToPlace = 40;
    }
    else if (level == "advanced") {
        minesToPlace = 99;
    }

    while (minesToPlace > 0) {
        int x = std::rand() % width;
        int y = std::rand() % height;

        if (!grid[x][y]->isMine) {
            grid[x][y]->isMine = true;
            --minesToPlace;
        }
    }
}


void Board::revealCell(int x, int y) {
    if (!isValidCell(x, y) || grid[x][y]->state != Cell::State::Unopened) {
        return;  // Ignore invalid or already opened cells
    }

    grid[x][y]->open();
    --remainingUnopenedCells;

    if (grid[x][y]->isMine) {
        // Handle mine hit, end the game
    } else {
        // Check and reveal adjacent cells if the current cell is blank
        if (grid[x][y]->adjacentMines == 0) {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    revealCell(x + dx, y + dy);
                }
            }
        }
    }
}


void Board::toggleFlag(int x, int y) {
    if (isValidCell(x, y) && grid[x][y]->state == Cell::State::Unopened) {
        grid[x][y]->toggleFlag();
    }
}

void Board::displayBoard() const {
    // Display the board on the console
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            switch (grid[x][y]->state) {
                case Cell::State::Unopened:
                    std::cout << "X ";
                    break;
                case Cell::State::Opened:
                    std::cout << (grid[x][y]->isMine ? "*" : std::to_string(grid[x][y]->adjacentMines)) << " ";
                    break;
                case Cell::State::Flagged:
                    std::cout << "F ";
                    break;
                case Cell::State::Questioned:
                    std::cout << "? ";
                    break;
            }
        }
        std::cout << std::endl;
    }
}

bool Board::isGameWon() const {
    // Check if the game is won
    return remainingUnopenedCells == totalMines;
}

bool Board::isValidCell(int x, int y) const {
    return (x >= 0 && x < width && y >= 0 && y < height);
}
