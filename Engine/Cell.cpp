#include "Cell.h"

Cell::Cell(Vec2DI& in_board_position)
	:
	board_position(in_board_position)
{

}

boolean Cell::open()
{
	state = State::Opened;
	return surrounding_mines == 0;
}

boolean Cell::isMined()
{
	return mined;
}

boolean Cell::isOpened() {
	return state == State::Opened;
}

void Cell::mine()
{
	mined = true;
}



void Cell::draw(SpriteCodex& spx, Graphics& gfx)
{
	switch (state)
	{
	case Cell::State::Hidden:
		spx.DrawTileButton(getScreenPosition(), gfx);
		break;
	case Cell::State::Opened:
		if (isMined()) {
			spx.DrawTileBomb(getScreenPosition(), gfx);
		}
		else {
			switch (surrounding_mines)
			{
			case 1:
				spx.DrawTile1(getScreenPosition(), gfx);
				break;
			case 2:
				spx.DrawTile2(getScreenPosition(), gfx);
				break;
			case 3:
				spx.DrawTile3(getScreenPosition(), gfx);
				break;
			case 4:
				spx.DrawTile4(getScreenPosition(), gfx);
				break;
			case 5:
				spx.DrawTile5(getScreenPosition(), gfx);
				break;
			case 6:
				spx.DrawTile6(getScreenPosition(), gfx);
				break;
			case 7:
				spx.DrawTile7(getScreenPosition(), gfx);
				break;
			case 8:
				spx.DrawTile8(getScreenPosition(), gfx);
				break;
			case 0:
				spx.DrawTile0(getScreenPosition(), gfx);
				break;
			default:
				break;
			}
		}
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

void Cell::setSurroundingMines(int in_surrounding_mines)
{
	surrounding_mines = in_surrounding_mines;
}

int Cell::getSurroundingMines() const
{
	return surrounding_mines;
}
