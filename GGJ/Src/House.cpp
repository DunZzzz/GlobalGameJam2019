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
	redrawSprite();
	ox::spActor target = sprite;
	target->addEventListener(ox::TouchEvent::CLICK, CLOSURE(this, &House::event));
}

void House::event(ox::Event *evt)
{
	ox::TouchEvent* te = ox::safeCast<ox::TouchEvent*>(evt);

	if (te->type == ox::TouchEvent::CLICK)
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
			//if (type == BURNED_HOUSE)
				//setNextType(HOUSE);
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
			attachImg("./assets/buildingTiles_022.png");
			break;
		case BURNING_HOUSE:
			attachImg("./assets/buildingTiles_022_burning.png");
			break;
		case BURNED_HOUSE:
			attachImg("./assets/buildingTiles_022_burned.png");
			break;
		default:
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
