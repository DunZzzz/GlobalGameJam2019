/*
 * Indestructible.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "Indestructible.hpp"
#include "Game.hpp"
#include "Exception.hpp"

#include <iostream>

Indestructible::Indestructible(Game *game, uint16_t *xy)
	: Tiles(game, xy, HOUSE)
{
	float pos[XY_SIZE];
	float size[XY_SIZE];

	size[X] = ((float)game->size[X] / (float)game->mapPreset->xy[X]);
	size[Y] = ((float)game->size[Y] / (float)game->mapPreset->xy[Y]);
	pos[X] = size[X] * xy[X];
	pos[Y] = size[Y] * xy[Y];
	sprite = new ox::ColorRectSprite;
	sprite->setPosition(pos[X], pos[Y]);
	sprite->setSize(size[X], size[Y]);
	sprite->attachTo(ox::getStage());
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
