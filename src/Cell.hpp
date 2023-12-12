#pragma once

#include <vector>
#include <memory>

template<typename T>
class Cell {
	bool Flagged;
	T x;
	bool Mine;
	bool isOpen;

	T surroundMines;
	T stateOfTheMouse;
	T y;
public:
	Cell(T Ix, T Iy);

	bool retIsOpen();
    bool open(std::vector<std::unique_ptr<Cell>>& i_cells);

	bool retIsFlag();
	bool retIsMine();

    void numMinesSurrounding(std::vector<std::unique_ptr<Cell>>& i_cells);
	void flag();
	
	T retMinesSurrounding();
	T mouseState();

	void reset();
	void mineSet();

	void MouseStateSet(T toSet);
};

template<typename T>
Cell<T>::Cell(T Ix, T Iy) : x(Ix), y(Iy), surroundMines(0), Flagged(false), isOpen(false), Mine(false), stateOfTheMouse(0) {
    reset();
}

template<typename T>
bool Cell<T>::retIsOpen() {
    return isOpen;
}

template<typename T>
bool Cell<T>::retIsFlag() {
    return Flagged;
}

template<typename T>
bool Cell<T>::retIsMine() {
    return Mine;
}

template<typename T>
bool Cell<T>::open(std::vector<std::unique_ptr<Cell>>& i_cells) {
    if (0 == isOpen) {
        isOpen = 1;

        if (!Mine && surroundMines == 0) {
            for (T a = -1; a < 2; a++) {
                for (T b = -1; b < 2; b++) {
                    const T neighborX = x + a;
                    const T neighborY = y + b;

                    if ((a != 0 || b != 0) && (neighborX >= 0 && neighborX < 8 && neighborY >= 0 && neighborY < 8)) {
                        retCell(i_cells, neighborX, neighborY) -> open(i_cells);
                    }
                }
            }
        }
        return Mine;
    }
    return 0;
}

template<typename T>
T Cell<T>::retMinesSurrounding() {
    return surroundMines;
}

template<typename T>
T Cell<T>::mouseState() {
    return stateOfTheMouse;
}

template<typename T>
void Cell<T>::numMinesSurrounding(std::vector<std::unique_ptr<Cell>>& i_cells) {
    surroundMines = 0;

    if (!Mine) {
        for (T a = -1; a < 2; a++) {
            for (T b = -1; b < 2; b++) {
                T neighborX = x + a;
                T neighborY = y + b;

                if ((a != 0 || b != 0) && (neighborX >= 0 && neighborX < 8 && neighborY >= 0 && neighborY < 8)) {
                    surroundMines += retCell(i_cells, neighborX, neighborY)->retIsMine();
                }
            }
        }
    }
}

template<typename T>
void Cell<T>::flag() {
    if (isOpen == 0) {
		if (Flagged == 1) {
			Flagged = 0;
		} else {
			Flagged = 1;
		}
	}
}

template<typename T>
void Cell<T>::reset() {
    isOpen = 0;
	stateOfTheMouse = 0;
	Flagged = 0;
	Mine = 0;
}

template<typename T>
void Cell<T>::mineSet() {
    Mine = 1;
}

template<typename T>
void Cell<T>::MouseStateSet(T toSet) {
    stateOfTheMouse = toSet;
}

