/*
 * Water.hpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

class Water;

#include "Indestructible.hpp"
#include "Exception.hpp"

class Water : public Indestructible
{
	public:
	Water(Game *game, uint16_t *xy);
	virtual ~Water();
	static Tiles *create(Game *game, uint16_t *xy);
};

