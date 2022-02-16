#pragma once
#include "Cell.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Randomizer.h"
class Board {
public:
	Board(int mines_amount);
	void generateMines();
	void draw(SpriteCodex& spx, Graphics& gfx);
	Cell& getCell(int x, int y);
private:
	Randomizer randomizer;
	Vec2DI mapIndex(int index) const;
	int mines_amount;
	const int x = 0;
	const int y = 0;
	static constexpr int cells_width = 6;
	static constexpr int cells_height = 6;
	static constexpr int cells_amount = cells_width * cells_height;
	Cell cells[cells_amount];
};