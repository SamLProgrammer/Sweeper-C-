#pragma once
#include "SpriteCodex.h"
#include "Vec2DI.h"
#include "Graphics.h"
class Cell {
public:
	Cell() = default;
	Cell(Vec2DI& in_board_position);
	enum class State {
		Hidden, Opened, Flagged, Exploding, Mined
	};
	void open();
	void flag();
	void mine();
	boolean isMined();
	void draw(SpriteCodex& spx, Graphics& gfx);
	int getWidth() const;
	int getHeight() const;
	int getX();
	int getY();
	Vec2DI getScreenPosition() const;
private:
	Vec2DI board_position;
	static constexpr int width = SpriteCodex::tileSize;
	static constexpr int height = SpriteCodex::tileSize;
	State state = State::Hidden;
};