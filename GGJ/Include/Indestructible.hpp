/*
 * Indestructible.hpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

class Indestructible;
class Tiles;

#include "Tiles.hpp"

class Indestructible : public Tiles
{
	public:
	Indestructible(Game *, uint16_t *);
	virtual ~Indestructible();
	void setNextType(const MAP_TILE &);
	void update();
	void event(ox::Event *evt);
};

