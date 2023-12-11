// #pragma once

// class GameBoard {
// 	bool click;
// 	char over;
// 	std::default_random_engine rando;
// 	std::random_device random_device;
// 	std::vector<Cell> cells;
// public:
// 	GameBoard();
// 	char retOver();
// 	void textDraw(const std::string& text, sf::RenderWindow& wdw, bool blackColor, unsigned short x, unsigned short y);
// 	void draw(sf::RenderWindow& i_window);
// 	void restart();
// 	unsigned short numFlags();

// 	void flag_cell(unsigned char flagx, unsigned char flagy);
// 	void openCell(unsigned char i_x, unsigned char i_y);

// 	void fieldMouseState(unsigned char i_mouse_state, unsigned char i_x, unsigned char i_y);
// };

#pragma once

#include <vector>
#include <random>
#include "Cell.hpp"  // Include the Cell header file

class GameBoard {
    bool click;
    char over;
    std::default_random_engine rando;
    std::random_device random_device;
    std::vector<Cell<unsigned char>> cells;  // Use Cell with a template parameter

public:
    GameBoard();
    char retOver();
    void textDraw(const std::string& text, sf::RenderWindow& wdw, bool blackColor, unsigned short x, unsigned short y);
    void draw(sf::RenderWindow& i_window);
    void restart();
    unsigned short numFlags();

    void flag_cell(unsigned char flagx, unsigned char flagy);
    void openCell(unsigned char i_x, unsigned char i_y);

    void fieldMouseState(unsigned char i_mouse_state, unsigned char i_x, unsigned char i_y);
};
