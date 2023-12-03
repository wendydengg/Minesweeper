#include "Game.hpp"
#include <iostream>

int main() {
    int width, height, mineCount;
    std::cout << "Enter board dimensions (width x height) and number of mines: ";
    std::cin >> width >> height >> mineCount;

    Game game(width, height, mineCount);
    game.run();

    return 0;
}
