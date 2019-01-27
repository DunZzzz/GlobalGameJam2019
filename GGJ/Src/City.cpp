/*
 * City.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "City.hpp"

City::City(Game *game, uint16_t *xy)
	: Indestructible(game, xy)
{
	attachImg("./assets/cityTiles_080.png");
}

City::~City()
{
}

Tiles *City::create(Game *game, uint16_t *xy)
{
	City *tile = new City(game, xy);

	if (tile == nullptr)
		throw err::excep("Out of Memory.");
	return tile;
}
