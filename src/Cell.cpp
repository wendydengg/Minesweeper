// #include <vector>

// #include "Cell.hpp"
// #include "retCell.hpp"

// Cell::Cell(unsigned char Ix, unsigned char Iy) : surroundMines(0), x(Ix), y(Iy) {
// 	reset();
// }

// bool Cell::retIsOpen() {
// 	return isOpen;
// }

// bool Cell::retIsFlag() {
// 	return Flagged;
// }

// bool Cell::retIsMine()
// {
// 	return Mine;
// }

// bool Cell::open(std::vector<Cell>& i_cells) {
// 	if (0 == isOpen) {
// 		isOpen = 1;

// 		if (Mine == 0 && surroundMines == 0) {
// 			for (char a = -1; a < 2; a++) {
// 				for (char b = -1; b < 2; b++) {
// 					const char neighborX = x + a;
// 					const char neighborY = y + b;

// 					// is neighbor in field
// 					if ((a != 0 || b != 0) && (neighborX >= 0 && neighborX < 8 && neighborY >= 0 && neighborY < 8)) {
// 						// neighbor cells open
// 						retCell(i_cells, neighborX, neighborY) -> open(i_cells);
// 					}
// 				}
// 			}
// 		}

// 		//cell has a mine?
// 		return Mine;
// 	}

// 	return 0;
// }


// unsigned char Cell::retMinesSurrounding() {
// 	return surroundMines;
// }

// unsigned char Cell::mouseState() {
// 	return stateOfTheMouse;
// }

// void Cell::numMinesSurrounding(std::vector<Cell>& i_cells) {
// 	//the mines around a cell
// 	surroundMines = 0;

// 		if (Mine == 0) {
// 			for (char a = -1; a < 2; a++) {
// 				for (char b = -1; b < 2; b++) {
// 					const char neighborX = x + a;
// 					const char neighborY = y + b;

// 					// checking if the neighbor is in the field
// 					if ((a != 0 || b != 0) && (neighborX >= 0 && neighborX < 8 && neighborY >= 0 && neighborY < 8)) {
// 						// increase by one when neighbor is mine
// 						surroundMines = surroundMines + retCell(i_cells, neighborX, neighborY) -> retIsMine();
// 					}
// 				}
// 			}
// 	}

// }

// void Cell::flag() {
// 	if (isOpen == 0) {
// 		if (Flagged == 1) {
// 			Flagged = 0;
// 		} else {
// 			Flagged = 1;
// 		}
// 	}
// }

// void Cell::reset() {
// 	isOpen = 0;
// 	stateOfTheMouse = 0;
// 	Flagged = 0;
// 	Mine = 0;
// }

// void Cell::mineSet() {
// 	Mine = 1;
// }

// void Cell::MouseStateSet(unsigned char toSet) {
// 	stateOfTheMouse = toSet;
// }

#include <vector>
#include "Cell.hpp"
#include "retCell.hpp"

template <typename T>
class Cell {
public:
    Cell(T Ix, T Iy);
    bool retIsOpen();
    bool retIsFlag();
    bool retIsMine();
    bool open(std::vector<Cell<T>>& i_cells);
    T retMinesSurrounding();
    T mouseState();
    void numMinesSurrounding(std::vector<Cell<T>>& i_cells);
    void flag();
    void reset();
    void mineSet();
    void MouseStateSet(T toSet);

private:
    unsigned char surroundMines;
    T x, y;
    unsigned char stateOfTheMouse;
    bool isOpen, Flagged, Mine;
};

// Constructor
template <typename T>
Cell<T>::Cell(T Ix, T Iy) : surroundMines(0), x(Ix), y(Iy), isOpen(false), Flagged(false), Mine(false) {
    reset();
}

// Methods
template <typename T>
bool Cell<T>::retIsOpen() {
    return isOpen;
}

template <typename T>
bool Cell<T>::retIsFlag() {
    return Flagged;
}

template <typename T>
bool Cell<T>::retIsMine() {
    return Mine;
}

template <typename T>
bool Cell<T>::open(std::vector<Cell<T>>& i_cells) {
    if (!isOpen) {
        isOpen = true;

        if (!Mine && surroundMines == 0) {
            for (T a = -1; a <= 1; ++a) {
                for (T b = -1; b <= 1; ++b) {
                    T neighborX = x + a;
                    T neighborY = y + b;

                    // Check if neighbor is in field
                    if ((a != 0 || b != 0) && (neighborX >= 0 && neighborX < 8 && neighborY >= 0 && neighborY < 8)) {
                        // Open neighbor cells
                        i_cells[neighborX * 8 + neighborY].open(i_cells);
                    }
                }
            }
        }
        return Mine;
    }
    return false;
}

template <typename T>
T Cell<T>::retMinesSurrounding() {
    return surroundMines;
}

template <typename T>
T Cell<T>::mouseState() {
    return stateOfTheMouse;
}

template <typename T>
void Cell<T>::numMinesSurrounding(std::vector<Cell<T>>& i_cells) {
    surroundMines = 0;

    if (!Mine) {
        for (T a = -1; a <= 1; ++a) {
            for (T b = -1; b <= 1; ++b) {
                T neighborX = x + a;
                T neighborY = y + b;

                // Check if neighbor is in the field
                if ((a != 0 || b != 0) && (neighborX >= 0 && neighborX < 8 && neighborY >= 0 && neighborY < 8)) {
                    // Increase count if neighbor is a mine
                    surroundMines += i_cells[neighborX * 8 + neighborY].retIsMine();
                }
            }
        }
    }
}

template <typename T>
void Cell<T>::flag() {
    if (!isOpen) {
        Flagged = !Flagged;
    }
}

template <typename T>
void Cell<T>::reset() {
    isOpen = false;
    stateOfTheMouse = 0;
    Flagged = false;
    Mine = false;
}

template <typename T>
void Cell<T>::mineSet() {
    Mine = true;
}

template <typename T>
void Cell<T>::MouseStateSet(T toSet) {
    stateOfTheMouse = toSet;
}