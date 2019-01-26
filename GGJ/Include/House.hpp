/*
 * House.hpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

class House;
class Tiles;

#include "Tiles.hpp"
#include "Oxygine.hpp"

class House : public Tiles
{
	public:
	House(Game *, uint16_t *);
	virtual ~House();
	static Tiles *create(Game *, uint16_t *);
	void setNextType(const MAP_TILE &);
	void update();
	void event(oxygine::Event *evt);
	void flush();

	private:
	oxygine::spSprite sprite;
	void redrawSprite();
};

