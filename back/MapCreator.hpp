/*
 * MapCreator.hpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

class MapCreator;
struct MapPreset;

#include <stdint.h>
#include <memory>
#include <vector>

enum MAP_TILE : uint16_t {
	GRASS,
	HOUSE,
	BURNING_HOUSE
};

enum XY : uint8_t {
	X,
	Y,
	XY_SIZE
};

using MapTiles = std::vector<std::vector<MAP_TILE>>;

struct MapPreset {
	MapTiles mapTiles;
	uint16_t xy[XY_SIZE];
};

class MapCreator
{
	public:
		MapCreator();
		virtual ~MapCreator();

		std::shared_ptr<MapPreset> randomMap();
		std::shared_ptr<MapPreset> map1();
};
