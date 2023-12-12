#pragma once

class GameBoard {
	bool click;
	char over;
	std::default_random_engine rando;
	std::random_device random_device;
	std::vector<Cell> cells;
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
// #pragma once
// #include <random>
// #include <SFML/Graphics.hpp>
// #include "Cell.hpp"

// enum class Difficulty { Easy, Medium, Hard };

// class GameBoard {
// 	bool click;
// 	char over;
// 	std::default_random_engine rando;
// 	std::random_device random_device;
// 	std::vector<Cell<unsigned char>> cells;
//     unsigned int boardSize;
//     unsigned int mineCount;
// public:
//     GameBoard(); 
// 	GameBoard(Difficulty difficulty);
// 	char retOver();
// 	void textDraw(const std::string& text, sf::RenderWindow& wdw, bool blackColor, unsigned short x, unsigned short y);
// 	void draw(sf::RenderWindow& i_window);
// 	void restart();
// 	unsigned short numFlags();

// 	void flag_cell(unsigned char flagx, unsigned char flagy);
// 	void openCell(unsigned char i_x, unsigned char i_y);

// 	void fieldMouseState(unsigned char i_mouse_state, unsigned char i_x, unsigned char i_y);

// private:
//     void initializeBoard(Difficulty difficulty);
//     void placeMines();
// };

