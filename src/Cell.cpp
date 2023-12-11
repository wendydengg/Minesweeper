#include <vector>

#include "Cell.hpp"
#include "retCell.hpp"

Cell::Cell(unsigned char Ix, unsigned char Iy) : surroundMines(0), x(Ix), y(Iy) {
	reset();
}

bool Cell::retIsOpen() {
	return isOpen;
}

bool Cell::retIsFlag() {
	return Flagged;
}

bool Cell::retIsMine()
{
	return Mine;
}

bool Cell::open(std::vector<Cell>& i_cells) {
	if (0 == isOpen) {
		isOpen = 1;

		if (Mine == 0 && surroundMines == 0) {
			for (char a = -1; a < 2; a++) {
				for (char b = -1; b < 2; b++) {
					const char neighborX = x + a;
					const char neighborY = y + b;

					// is neighbor in field
					if ((a != 0 || b != 0) && (neighborX >= 0 && neighborX < 8 && neighborY >= 0 && neighborY < 8)) {
						// neighbor cells open
						retCell(i_cells, neighborX, neighborY) -> open(i_cells);
					}
				}
			}
		}

		//cell has a mine?
		return Mine;
	}

	return 0;
}


unsigned char Cell::retMinesSurrounding() {
	return surroundMines;
}

unsigned char Cell::mouseState() {
	return stateOfTheMouse;
}

void Cell::numMinesSurrounding(std::vector<Cell>& i_cells) {
	//the mines around a cell
	surroundMines = 0;

		if (Mine == 0) {
			for (char a = -1; a < 2; a++) {
				for (char b = -1; b < 2; b++) {
					const char neighborX = x + a;
					const char neighborY = y + b;

					// checking if the neighbor is in the field
					if ((a != 0 || b != 0) && (neighborX >= 0 && neighborX < 8 && neighborY >= 0 && neighborY < 8)) {
						// increase by one when neighbor is mine
						surroundMines = surroundMines + retCell(i_cells, neighborX, neighborY) -> retIsMine();
					}
				}
			}
	}

}

void Cell::flag() {
	if (isOpen == 0) {
		if (Flagged == 1) {
			Flagged = 0;
		} else {
			Flagged = 1;
		}
	}
}

void Cell::reset() {
	isOpen = 0;
	stateOfTheMouse = 0;
	Flagged = 0;
	Mine = 0;
}

void Cell::mineSet() {
	Mine = 1;
}

void Cell::MouseStateSet(unsigned char toSet) {
	stateOfTheMouse = toSet;
}