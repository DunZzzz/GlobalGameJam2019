/*
 * Water.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "Water.hpp"

Water::Water(Game *game, uint16_t *xy)
	: Indestructible(game, xy)
{
	attachImg("./assets/landscapeTiles_066.png");
}

Water::~Water()
{
}

Tiles *Water::create(Game *game, uint16_t *xy)
{
	Water *tile = new Water(game, xy);

	if (tile == nullptr)
		throw err::excep("Out of Memory.");
	return tile;
}
