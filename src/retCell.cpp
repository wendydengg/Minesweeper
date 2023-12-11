#include <vector>

#include "Cell.hpp"
#include "retCell.hpp"

Cell<unsigned char>* retCell(std::vector<Cell<unsigned char>>& i_cells, unsigned char ix, unsigned char iy) {
	return &i_cells[ix + 8 * iy];
}