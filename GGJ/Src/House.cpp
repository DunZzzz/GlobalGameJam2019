/*
 * House.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "House.hpp"
#include "Game.hpp"
#include "Exception.hpp"

#include <iostream>

House::House(Game *game, uint16_t *xy)
	: Tiles(game, xy, HOUSE)
{
	float pos[XY_SIZE];
	float size[XY_SIZE];

	size[X] = ((float)game->size[X] / (float)game->mapPreset->xy[X]);
	size[Y] = ((float)game->size[Y] / (float)game->mapPreset->xy[Y]);
	pos[X] = size[X] * xy[X];
	pos[Y] = size[Y] * xy[Y];
	sprite = new oxygine::ColorRectSprite;
	sprite->setPosition(pos[X], pos[Y]);
	sprite->setSize(size[X], size[Y]);
	sprite->attachTo(oxygine::getStage()); 
	redrawSprite();
	oxygine::spActor target = sprite;
	target->addEventListener(oxygine::TouchEvent::CLICK, CLOSURE(this, &House::event));
}

void House::event(oxygine::Event *evt)
{
	oxygine::TouchEvent* te = oxygine::safeCast<oxygine::TouchEvent*>(evt);

	if (te->type == oxygine::TouchEvent::CLICK)
		setNextType(BURNING_HOUSE);
}


House::~House()
{
}

void House::update()
{
	int tmp = 0;

	if (xy[X] > 0 && game->currentMap.at(xy[X] - 1).at(xy[Y])->type == BURNING_HOUSE)
		tmp++;
	if (xy[Y] > 0 && game->currentMap.at(xy[X]).at(xy[Y] - 1)->type == BURNING_HOUSE)
		tmp++;

	if ((xy[X] + 1) < game->mapPreset->xy[X] && game->currentMap.at(xy[X] + 1).at(xy[Y])->type == BURNING_HOUSE)
		tmp++;
	if ((xy[Y] + 1) < game->mapPreset->xy[Y] && game->currentMap.at(xy[X]).at(xy[Y] + 1)->type == BURNING_HOUSE)
		tmp++;
	switch (tmp) {
		case 0:
			if (type == BURNING_HOUSE)
				setNextType(BURNED_HOUSE);
			if (type == BURNED_HOUSE)
				setNextType(HOUSE);
			break;
		case 1:
			if (type == BURNING_HOUSE)
				setNextType(BURNED_HOUSE);
			if (type == HOUSE)
				setNextType(BURNING_HOUSE);
			break;
		case 2:
			if (type == HOUSE)
				setNextType(BURNING_HOUSE);
			break;
		case 3:
			if (type == BURNING_HOUSE)
				setNextType(BURNED_HOUSE);
			else
				setNextType(BURNING_HOUSE);
			break;
		default:
			break;
	}
}

void House::redrawSprite()
{
	switch (type) {
		case HOUSE:
			sprite->setColor(oxygine::Color(57, 64, 80, 255));
			break;
		case BURNING_HOUSE:
			sprite->setColor(oxygine::Color(229, 21, 17, 255));
			break;
		case BURNED_HOUSE:
			sprite->setColor(oxygine::Color(32, 32, 32, 255));
			break;
		case GRASS:
			sprite->setColor(oxygine::Color(22, 92, 21, 255));
			break;
		default:
			sprite->setColor(oxygine::Color(255, 255, 255, 255));
			break;
	}
}

void House::flush()
{
	if (nextType != NONE) {
		type = nextType;
		nextType = NONE;
		redrawSprite();
	}
}

void House::setNextType(const MAP_TILE &type)
{
	nextType = type;
}

Tiles *House::create(Game *game, uint16_t *xy)
{
	House *tile = new House(game, xy);

	if (tile == nullptr)
		throw err::excep("Out of Memory.");
	return tile;
}
