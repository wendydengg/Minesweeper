// Game.cpp
#include "Game.hpp"
#include <iostream>

Game::Game(int width, int height, int mineCount) : gameOver(false) {
    board = std::make_unique<Board>(width, height);
    board->placeMines(mineCount);
}


void Game::run() {
    while (!gameOver) {
        board->displayBoard();
        // Handle user input and game logic

        gameOver = board->isGameWon();  
    }
}
