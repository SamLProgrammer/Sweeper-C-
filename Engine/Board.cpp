#include "Board.h"

Board::Board(int in_mines_amount)
{
	mines_amount = in_mines_amount;
	for (int i = 0; i < cells_amount; i++) {
		cells[i] = Cell(mapIndex(i));
	}
	generateMines();
}

void Board::generateMines()
{
		int x = 0;
		int y = 0;
	for (int i = mines_amount; i > -1; i--) {
		do {
			x = randomizer.getRandomInt(0, height_in_cells);
			y = randomizer.getRandomInt(0, width_in_cells);
		} while (getCell(x, y).isMined());
		getCell(x, y).mine();
	}
}



void Board::draw(SpriteCodex& spx, Graphics& gfx)
{
	for (int i = 0; i < cells_amount; i++) {
		cells[i].draw(spx, gfx);
	}
}

void Board::processClick(int x, int y)
{
	int x_cell = xScreenToCell(x);
	int y_cell = yScreenToCell(y);
 }

int Board::xScreenToCell(int in_x) {
	return in_x/Cell::width;
}

int Board::yScreenToCell(int in_y) {
	return in_y / Cell::height;
}

Cell& Board::getCell(int x, int y)
{
	return cells[width_in_cells * y + x];
}

Vec2DI Board::mapIndex(int index) const
{
	return Vec2DI(index % width_in_cells, index / width_in_cells);
}


