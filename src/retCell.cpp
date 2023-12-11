#include <vector>

#include "Cell.hpp"
#include "retCell.hpp"

template <typename T>
Cell<T>& retCell(std::vector<Cell<T>>& cells, T x, T y) {
    // Assume that cells are stored in a linear vector
    // and access them based on 2D grid coordinates (x, y).
    return cells[x * 8 + y]; 
}