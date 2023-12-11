#pragma once

class Cell {
	bool Flagged;
	unsigned char x;
	bool Mine;
	bool isOpen;

	unsigned char surroundMines;
	unsigned char stateOfTheMouse;
	unsigned char y;
public:
	Cell(unsigned char Ix, unsigned char Iy);

	bool retIsOpen();
	bool open(std::vector<Cell>& i_cells);

	bool retIsFlag();
	bool retIsMine();

	void numMinesSurrounding(std::vector<Cell>& i_cells);
	void flag();
	
	unsigned char retMinesSurrounding();
	unsigned char mouseState();

	void reset();
	void mineSet();

	void MouseStateSet(unsigned char toSet);
};