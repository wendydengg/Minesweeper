#include <vector>

#include "Cell.hpp"
#include "retCell.hpp"

Cell<int>* retCell(std::vector<std::unique_ptr<Cell<int>>>& i_cells, unsigned char ix, unsigned char iy) {
    return i_cells[ix + 8 * iy].get();
}