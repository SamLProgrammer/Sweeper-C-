#include "Board.h"

Board::Board(int in_mines_amount)
{
	mines_amount = in_mines_amount;
	for (int i = 0; i < cells_amount; i++) {
		cells[i] = Cell(mapIndex(i));
	}
}

void Board::draw(SpriteCodex& spx, Graphics& gfx)
{
	for (int i = 0; i < cells_amount; i++) {
		cells[i].draw(spx, gfx);
	}
}

Vec2DI Board::mapIndex(int index) const
{
	return Vec2DI(index % cells_width, index / cells_width);
}


