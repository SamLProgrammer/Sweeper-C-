#include "Board.h"

Board::Board(int in_mines_amount)
{
	mines_amount = in_mines_amount;
	for (int i = 0; i < cells_amount; i++) {
		cells[i] = Cell(mapIndex(i));
	}
	generateMines();
	for (int i = 0; i < width_in_cells; i++) {
		for (int j = 0; j < height_in_cells; j++) {
			surroundingMines(i, j);
		}
	}
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
	if (getCell(x_cell, y_cell).open()) {
		spreadOpenning(x_cell, y_cell);
	}
 }

void Board::spreadOpenning(int x, int y) {

	for (int i = x - 1; i < x + 2; i++) {

		for (int j = y - 1; j < y + 2; j++) {

			if (validPosition(i, j) && !getCell(i, j).isOpened()) {
				getCell(i, j).open();
				if (getCell(i, j).getSurroundingMines() == 0) {
					spreadOpenning(i, j);
				}
			}

		}

	}
}


int Board::xScreenToCell(int in_x) {
	return in_x/Cell::width;
}

int Board::yScreenToCell(int in_y) {
	return in_y / Cell::height;
}

void Board::surroundingMines(int x, int y)
{
	Cell& cell = getCell(x, y);
	int surrounding_mines = 0;
	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			surrounding_mines = (validPosition(i,j) && getCell(i,j).isMined()) ? surrounding_mines + 1 : surrounding_mines;
		}
	}
	cell.setSurroundingMines(surrounding_mines);
}

boolean Board::validPosition(int x, int y)
{
	return !( x < 0 || x > width_in_cells - 1 || y < 0 || y > height_in_cells - 1 );
}

Cell& Board::getCell(int x, int y)
{
	return cells[width_in_cells * y + x];
}

Vec2DI Board::mapIndex(int index) const
{
	return Vec2DI(index % width_in_cells, index / width_in_cells);
}


