// #pragma once

// Cell* retCell(std::vector<Cell>& i_cells, unsigned char ix, unsigned char iy);

#pragma once

#include <vector>
#include "Cell.hpp" 

template <typename T>
Cell<T>& retCell(std::vector<Cell<T>>& cells, T x, T y); 