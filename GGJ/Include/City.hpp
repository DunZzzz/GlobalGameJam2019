/*
 * City.hpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

class City;

#include "Indestructible.hpp"
#include "Exception.hpp"

class City : public Indestructible
{
	public:
	City(Game *game, uint16_t *xy);
	virtual ~City();
	static Tiles *create(Game *game, uint16_t *xy);
};

