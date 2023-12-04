// main.cpp
#include "Game.hpp"
#include <iostream>

int main() {
    std::string difficulty;
    int width, height, mineCount;
    std::cout << "Enter difficulty level (beginner, intermediate, advanced):";
    std::cin >> width >> height >> mineCount;

    Game game(difficulty); 
    game.run();

    return 0;
}
