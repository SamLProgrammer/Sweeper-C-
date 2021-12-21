#include "Cell.h"

Cell::Cell(Vec2DI& in_board_position)
	:
	board_position(in_board_position)
{

}

void Cell::draw(SpriteCodex& spx, Graphics& gfx)
{
	spx.DrawTileButton(getScreenPosition(), gfx);
}

int Cell::getWidth() const
{
	return width;
}

int Cell::getHeight() const
{
	return height;
}

int Cell::getX()
{
	return board_position.getX();
}

int Cell::getY()
{
	return board_position.getY();
}

Vec2DI Cell::getScreenPosition() const
{
	return Vec2DI(board_position.getX() * width, board_position.getY() * height);
}
