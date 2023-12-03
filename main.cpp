// main.cpp
#include "Game.hpp"
#include <iostream>

int main() {
    int width, height, mineCount;
    std::cout << "Enter difficulty level (beginner, intermediate, advanced):";
    std::cin >> width >> height >> mineCount;

    Game game(width, height, mineCount);
    game.run();

    return 0;
}
