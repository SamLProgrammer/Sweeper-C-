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
	void processClick(int x, int y);
	Cell& getCell(int x, int y);
	int xScreenToCell(int in_x);
	int yScreenToCell(int in_y);
private:
	Randomizer randomizer;
	Vec2DI mapIndex(int index) const;
	int mines_amount;
	const int x = 0;
	const int y = 0;
	static constexpr int width_in_cells = 6;
	static constexpr int height_in_cells = 6;
	static constexpr int cells_amount = width_in_cells * height_in_cells;
	Cell cells[cells_amount];
};