/*
 * Tiles.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "Tiles.hpp"
#include "Game.hpp"

#include <iostream>

Tiles::Tiles(Game *game, uint16_t *xy, MAP_TILE type)
	: game(game) , xy{xy[X], xy[Y]} , type(type), nextType(NONE), flamePower(0)
{
	size[X] = 64;
	size[Y] = 64;
	pos[X] = size[X] * xy[X];
	pos[Y] = size[Y] * xy[Y];

	// ISOMETRIC VIEW

	float tmpPos[XY_SIZE];
	tmpPos[X] = pos[X] - pos[Y];
	tmpPos[Y] = (pos[X] + pos[Y]) / 2;

	pos[X] = tmpPos[X] - size[X] + game->size[X] / 2;
	pos[Y] = tmpPos[Y] - size[Y] + game->size[Y] / 2;

	// END -- ISOMETRIC VIEW

	sprite = new ox::Sprite();
	sprite->setPosition(pos[X], pos[Y]);
	sprite->setSize(size[X], size[Y]);
	sprite->attachTo(ox::getStage());
}

void Tiles::attachImg(const std::string &path)
{
	ox::SingleResAnim *img = new ox::SingleResAnim();

	img->init(path);
	sprite->setPosition(pos[X], pos[Y] - img->getHeight());
	sprite->setResAnim(img);
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
	sprite->detach();
}
