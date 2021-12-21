#pragma once
#include "Cell.h"
#include "Graphics.h"
#include "SpriteCodex.h"
class Board {
public:
	Board(int mines_amount);
	void draw(SpriteCodex& spx, Graphics& gfx);
private:
	Vec2DI mapIndex(int index) const;
	int mines_amount;
	const int x = 0;
	const int y = 0;
	static constexpr int cells_width = 12;
	static constexpr int cells_height = 20;
	static constexpr int cells_amount = cells_width * cells_height;
	Cell cells[cells_amount];
};