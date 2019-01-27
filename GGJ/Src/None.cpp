/*
 * None.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "None.hpp"

None::None(Game *game, uint16_t *xy)
	: Indestructible(game, xy)
{
}

None::~None()
{
}

Tiles *None::create(Game *game, uint16_t *xy)
{
	None *tile = new None(game, xy);

	if (tile == nullptr)
		throw err::excep("Out of Memory.");
	return tile;
}
