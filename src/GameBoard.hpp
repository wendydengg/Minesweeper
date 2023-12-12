#pragma once

class GameBoard {
	bool click;
	char over;
	std::default_random_engine rando;
    std::vector<std::unique_ptr<Cell<int>>> cells;
public:
	GameBoard();
	char retOver();
	void textDraw(const std::string& text, sf::RenderWindow& wdw, bool blackColor, unsigned short x, unsigned short y);
	void draw(sf::RenderWindow& wdw);
	void restart();
	unsigned short numFlags();

	void flag_cell(unsigned char flagx, unsigned char flagy);
	void openCell(unsigned char ix, unsigned char iy);

	void fieldMouseState(unsigned char isMouse, unsigned char ix, unsigned char iy);
};
