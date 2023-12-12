#include <vector>

#include "Cell.hpp"
#include "retCell.hpp"

Cell* retCell(std::vector<Cell>& i_cells, unsigned char ix, unsigned char iy) {
	return &i_cells[ix + 8 * iy];
}