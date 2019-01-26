/*
 * Tiles.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "Tiles.hpp"

Tiles::Tiles(Game *game, uint16_t *xy, MAP_TILE type)
	: game(game) , xy{xy[X], xy[Y]} , type(type), nextType(NONE)
{
}

void Tiles::flush()
{
	if (nextType != NONE) {
		type = nextType;
		nextType = NONE;
	}
}

Tiles::~Tiles()
{
}
