// Cell.tpp - Template Implementation for Cell class

template<typename T>
Cell<T>::Cell(T Ix, T Iy) : x(Ix), y(Iy), surroundMines(0), isOpen(0), stateOfTheMouse(0), Flagged(0), Mine(0) {
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
bool Cell<T>::open(std::vector<Cell<T>>& i_cells) {
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

template<typename T>
T Cell<T>::retMinesSurrounding() {
    return surroundMines;
}

template<typename T>
unsigned char Cell<T>::mouseState() {
    return stateOfTheMouse;
}

template<typename T>
void Cell<T>::numMinesSurrounding(std::vector<Cell<T>>& i_cells) {
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
void Cell<T>::MouseStateSet(unsigned char toSet) {
    stateOfTheMouse = toSet;
}
