// Game.cpp
#include "Game.hpp"
#include <iostream>

Game::Game(std::string difficulty) : gameOver(false) {
    board = std::make_unique<Board>(difficulty);
    board->placeMines();
}


void Game::run() {
    while (!gameOver) {
        board->displayBoard();
        // Handle user input and game logic

        gameOver = board->isGameWon();  
    }
}
