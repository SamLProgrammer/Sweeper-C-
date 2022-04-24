#pragma once
#include "SpriteCodex.h"
#include "Vec2DI.h"
#include "Graphics.h"
class Cell {
public:
	Cell() = default;
	Cell(Vec2DI& in_board_position);
	enum class State {
		Hidden, Opened, Flagged, Exploding
	};
	boolean open();
	boolean isMined();
	boolean isOpened();
	void flag();
	void mine();
	void draw(SpriteCodex& spx, Graphics& gfx);
	int getWidth() const;
	int getHeight() const;
	int getX();
	int getY();
	Vec2DI getScreenPosition() const;
	static constexpr int width = SpriteCodex::tileSize;
	static constexpr int height = SpriteCodex::tileSize;
	void setSurroundingMines(int in_surrounding_mines);
	int getSurroundingMines() const;
private:
	boolean mined = false;
	Vec2DI board_position;
	State state = State::Hidden;
	int surrounding_mines = 0;
};