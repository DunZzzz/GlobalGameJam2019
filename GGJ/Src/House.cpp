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

	if (te->type == ox::TouchEvent::CLICK) {
		flamePower = 100;
		setNextType(BURNING_HOUSE);
	}
}


House::~House()
{
}

void House::update()
{
	int tmp = 0;

	if (xy[X] > 0 && game->currentMap.at(xy[X] - 1).at(xy[Y])->type == BURNING_HOUSE)
		tmp += game->currentMap.at(xy[X] - 1).at(xy[Y])->flamePower;
	if (xy[Y] > 0 && game->currentMap.at(xy[X]).at(xy[Y] - 1)->type == BURNING_HOUSE)
		tmp += game->currentMap.at(xy[X]).at(xy[Y] - 1)->flamePower;
	if ((xy[X] + 1) < game->mapPreset->xy[X] && game->currentMap.at(xy[X] + 1).at(xy[Y])->type == BURNING_HOUSE)
		tmp += game->currentMap.at(xy[X] + 1).at(xy[Y])->flamePower;
	if ((xy[Y] + 1) < game->mapPreset->xy[Y] && game->currentMap.at(xy[X]).at(xy[Y] + 1)->type == BURNING_HOUSE)
		tmp += game->currentMap.at(xy[X]).at(xy[Y] + 1)->flamePower;

	if (tmp < 3) {
		if (type == BURNING_HOUSE) {
			flamePower -= 2;
			if (flamePower <= 0)
				setNextType(BURNED_HOUSE);
		}
	} else if (tmp < 6) {
		if (type == BURNING_HOUSE) {
			flamePower--;
			if (flamePower <= 0)
				setNextType(BURNED_HOUSE);
		}
	} else if (tmp < 9) {
		if (type == HOUSE) {
			flamePower = (float)tmp * 0.6f;
			setNextType(BURNING_HOUSE);
		}
	} else {
		if (type == BURNING_HOUSE)
			setNextType(BURNED_HOUSE);
		else if (type != BURNED_HOUSE) {
			flamePower = (float)tmp * 0.6f;
			setNextType(BURNING_HOUSE);
		}
	}
	flamePower--;
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
