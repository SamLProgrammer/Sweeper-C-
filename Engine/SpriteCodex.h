#pragma once

#include "Graphics.h"
#include "Vec2DF.h"

class SpriteCodex
{
public:
	// width and height of all tiles
	static constexpr int tileSize = 16;
	// base color for all tiles
	static constexpr Color baseColor = { 192,192,192 };
	// 16x16 tile sprites assume (192,192,192) background and top left origin
	static void DrawTile0(const Vec2DF& pos, Graphics& gfx);
	static void DrawTile1(const Vec2DF& pos, Graphics& gfx);
	static void DrawTile2(const Vec2DF& pos, Graphics& gfx);
	static void DrawTile3(const Vec2DF& pos, Graphics& gfx);
	static void DrawTile4(const Vec2DF& pos, Graphics& gfx);
	static void DrawTile5(const Vec2DF& pos, Graphics& gfx);
	static void DrawTile6(const Vec2DF& pos, Graphics& gfx);
	static void DrawTile7(const Vec2DF& pos, Graphics& gfx);
	static void DrawTile8(const Vec2DF& pos, Graphics& gfx);
	static void DrawTileButton(const Vec2DF& pos, Graphics& gfx);
	static void DrawTileCross(const Vec2DF& pos, Graphics& gfx);
	static void DrawTileFlag(const Vec2DF& pos, Graphics& gfx);
	static void DrawTileBomb(const Vec2DF& pos, Graphics& gfx);
	static void DrawTileBombRed(const Vec2DF& pos, Graphics& gfx);
	// Tile selector function valid input 0-8
	static void DrawTileNumber(const Vec2DF& pos, int n, Graphics& gfx);
	// Win Screen 254x192 center origin
	static void DrawWin(const Vec2DF& pos, Graphics& gfx);
};