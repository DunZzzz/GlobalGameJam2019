/*
 * Indestructible.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "Indestructible.hpp"
#include "Exception.hpp"

#include <iostream>

Indestructible::Indestructible(Game *game, uint16_t *xy)
	: Tiles(game, xy, HOUSE)
{
}

Indestructible::~Indestructible()
{
}

void Indestructible::update()
{
}

void Indestructible::setNextType(const MAP_TILE &type)
{
	nextType = type;
}
