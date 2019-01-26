/*
 * Tiles.hpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

class Tiles;
class Game;

#include "MapCreator.hpp"

#include <stdint.h>
#include <memory>

class Tiles
{
	public:
		Tiles(Game *, uint16_t *, MAP_TILE);
		virtual ~Tiles();
		virtual void setNextType(const MAP_TILE &) = 0;
		virtual void update() = 0;
		virtual void flush();

		MAP_TILE type;

	protected:
		MAP_TILE nextType;
		Game *game;
		uint16_t xy[2];
};

