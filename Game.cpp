// Game.cpp
#include "Game.hpp"
#include <iostream>

Game::Game(int width, int height, int mineCount) : board(width, height), gameOver(false) {
    board.placeMines(mineCount);
}

void Game::run() {
    while (!gameOver) {
        board.displayBoard();
        // Handle user input and game logic

        gameOver = board.isGameWon();  
    }
}
