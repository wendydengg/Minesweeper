#ifndef CELL_HPP
#define CELL_HPP

#include <vector>
#include <cstddef> 

template<typename T>
class Cell {
public:
    Cell(T Ix, T Iy);
    bool retIsOpen();
    bool retIsFlag();
    bool retIsMine();
    bool open(std::vector<Cell<T>>& i_cells);
    T retMinesSurrounding();
    unsigned char mouseState();
    void numMinesSurrounding(std::vector<Cell<T>>& i_cells);
    void flag();
    void reset();
    void mineSet();
    void MouseStateSet(unsigned char toSet);

private:
    unsigned char surroundMines, isOpen, stateOfTheMouse, Flagged, Mine;
    T x, y;
};

#include "Cell.tpp" 

#endif 
