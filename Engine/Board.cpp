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
	for (int i = mines_amount; i > -1; i--) {
		int x = 0;
		int y = 0;
		do {
			x = randomizer.getRandomInt(0, cells_height);
			y = randomizer.getRandomInt(0, cells_width);
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

Cell& Board::getCell(int x, int y)
{
	return cells[cells_width * y + x];
}

Vec2DI Board::mapIndex(int index) const
{
	return Vec2DI(index % cells_width, index / cells_width);
}


