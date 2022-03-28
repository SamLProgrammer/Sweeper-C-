#include "Cell.h"

Cell::Cell(Vec2DI& in_board_position)
	:
	board_position(in_board_position)
{

}

void Cell::open()
{
	state = State::Opened;
}

void Cell::mine()
{
	mined = true;
}

boolean Cell::isMined()
{
	return mined;
}

void Cell::draw(SpriteCodex& spx, Graphics& gfx)
{
	switch (state)
	{
	case Cell::State::Hidden:
		spx.DrawTileButton(getScreenPosition(), gfx);
		break;
	case Cell::State::Opened:
		break;
	case Cell::State::Flagged:
		break;
	case Cell::State::Exploding:
		break;
	default:
		break;
	}
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
