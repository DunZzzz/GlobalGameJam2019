/*
 * None.hpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

class None;

#include "Indestructible.hpp"
#include "Exception.hpp"

class None : public Indestructible
{
	public:
	None(Game *game, uint16_t *xy);
	virtual ~None();
	static Tiles *create(Game *game, uint16_t *xy);
};

