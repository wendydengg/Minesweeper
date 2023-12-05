// Game.cpp
#include "Game.hpp"
#include <iostream>

Game::Game(const std::string& diff) : difficulty(diff), gameOver(false) {
    int width, height, mineCount;

    if (difficulty == "beginner") {
        width = 9; height = 9; mineCount = 10;
    } else if (difficulty == "intermediate") {
        width = 16; height = 16; mineCount = 40;
    } else if (difficulty == "advanced") {
        width = 24; height = 24; mineCount = 99;
    } else {
        std::cerr << "Invalid difficulty. Defaulting to beginner level.\n";
        width = 9; height = 9; mineCount = 10;
    }

    board = std::make_unique<Board<Cell<int>>>(width, height, mineCount);
    board->placeMines();
}

void Game::run() {
    while (!gameOver) {
        // implement logic:

        gameOver = board->isGameWon();  
    }
}
