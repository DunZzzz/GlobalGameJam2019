/*
 * Grass.hpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

class Grass;

#include "Indestructible.hpp"
#include "Exception.hpp"

class Grass : public Indestructible
{
	public:
	Grass(Game *game, uint16_t *xy);
	virtual ~Grass();
	static Tiles *create(Game *game, uint16_t *xy);
};

