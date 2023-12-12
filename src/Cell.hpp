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

// #ifndef CELL_HPP
// #define CELL_HPP

// #include <vector>
// #include <cstddef> 

// template<typename T>
// class Cell {
// public:
//     Cell(T Ix, T Iy);
//     bool retIsOpen();
//     bool retIsFlag();
//     bool retIsMine();
//     bool open(std::vector<Cell<T>>& i_cells);
//     T retMinesSurrounding();
//     unsigned char mouseState();
//     void numMinesSurrounding(std::vector<Cell<T>>& i_cells);
//     void flag();
//     void reset();
//     void mineSet();
//     void MouseStateSet(unsigned char toSet);

// private:
//     unsigned char surroundMines, isOpen, stateOfTheMouse, Flagged, Mine;
//     T x, y;
// };

// #include "Cell.tpp" 

// #endif 
