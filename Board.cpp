#include "Board.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
Board<T>::Board(int w, int h, int mC) : width(w), height(h), mineCount(mC), 
    remainingUnopenedCells(w * h), grid(w, std::vector<std::unique_ptr<T>>(h)) {
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            grid[x][y] = std::make_unique<T>();
        }
    }
}

template<typename T>
void Board<T>::placeMines() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int minesToPlace = mineCount;
    while (minesToPlace > 0) {
        int x = std::rand() % width;
        int y = std::rand() % height;

        if (!grid[x][y]->isMine()) {
            grid[x][y]->setMine(true);
            --minesToPlace;

            // Increment adjacent mines count for surrounding cells
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (isValidCell(x + dx, y + dy)) {
                        grid[x + dx][y + dy]->incrementAdjacentMines();
                    }
                }
            }
        }
    }
}

template<typename T>
void Board<T>::revealCell(int x, int y) {
    if (!isValidCell(x, y) || grid[x][y]->state() != T::State::Unopened) {
        return;
    }

    grid[x][y]->open();
    --remainingUnopenedCells;

    if (grid[x][y]->isMine()) {
        gameOver = true;
    } else if (grid[x][y]->adjacentMines() == 0) {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx != 0 || dy != 0) {
                    revealCell(x + dx, y + dy);
                }
            }
        }
    }
}

template<typename T>
void Board<T>::toggleFlag(int x, int y) {
    if (isValidCell(x, y) && grid[x][y]->state() == T::State::Unopened) {
        grid[x][y]->toggleFlag();
    }
}

template<typename T>
void Board<T>::displayBoard() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            switch (grid[x][y]->state()) {
                case T::State::Unopened:
                    std::cout << ".";
                    break;
                case T::State::Opened:
                    if (grid[x][y]->isMine()) {
                        std::cout << "*";
                    } else {
                        std::cout << grid[x][y]->adjacentMines();
                    }
                    break;
                case T::State::Flagged:
                    std::cout << "F";
                    break;
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
}

template<typename T>
bool Board<T>::isGameWon() const {
    return remainingUnopenedCells == mineCount;
}

template<typename T>
std::pair<int, int> Board<T>::getHint() {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (!grid[x][y]->isMine() && grid[x][y]->state() == T::State::Unopened) {
                return {x, y};
            }
        }
    }
    return {-1, -1}; 
}

template<typename T>
bool Board<T>::isValidCell(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

template class Board<Cell<int>>;