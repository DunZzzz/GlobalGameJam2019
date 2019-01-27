/*
 * MapCreator.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "MapCreator.hpp"

#include <stdlib.h>

MapCreator::MapCreator()
{
}

MapCreator::~MapCreator()
{
}

std::shared_ptr<MapPreset> MapCreator::randomMap()
{
	std::vector<std::shared_ptr<MapPreset> (MapCreator::*)()> pool = {
		&MapCreator::map1,
		&MapCreator::map2,
		&MapCreator::map3,
	};

	return ((*this).*(pool.at(rand() % pool.size())))();
}

std::shared_ptr<MapPreset> MapCreator::map1()
{
	auto mapPreset = std::make_shared<MapPreset>();

	for (uint16_t i = 0; i < 200; i++) {
		std::vector<MAP_TILE> tileset;
		for (uint16_t j = 0; j < 200; j++) {
			tileset.push_back(HOUSE);
		}
		mapPreset->mapTiles.push_back(tileset);
	}
	mapPreset->xy[X] = 10;
	mapPreset->xy[Y] = 10;
	mapPreset->mapTiles = {
		{NONE, NONE, GRASS, GRASS, GRASS, GRASS, NONE, NONE, NONE, NONE},
		{NONE, GRASS, GRASS, HOUSE, HOUSE, HOUSE, GRASS, NONE, NONE, NONE},
		{GRASS, GRASS, GRASS, HOUSE, HOUSE, HOUSE, HOUSE, GRASS, NONE, NONE},
		{GRASS, GRASS, HOUSE, HOUSE, ROAD, ROAD, ROAD, HOUSE, GRASS, NONE},
		{WATER, GRASS, GRASS, HOUSE, HOUSE, HOUSE, ROAD, HOUSE, GRASS, GRASS},
		{WATER, GRASS, GRASS, HOUSE, HOUSE, HOUSE, ROAD, HOUSE, GRASS, GRASS},
		{NONE, WATER, GRASS, GRASS, HOUSE, HOUSE, ROAD, HOUSE, GRASS, NONE},
		{NONE, NONE, WATER, WATER, GRASS, HOUSE, HOUSE, HOUSE, GRASS, NONE},
		{NONE, NONE, NONE, WATER, WATER, GRASS, GRASS, GRASS, NONE, NONE},
		{NONE, NONE, NONE, NONE, WATER, WATER, GRASS, NONE, NONE, NONE},
	};
	return mapPreset;
}

std::shared_ptr<MapPreset> MapCreator::map2()
{
	auto mapPreset = std::make_shared<MapPreset>();

	for (uint16_t i = 0; i < 200; i++) {
		std::vector<MAP_TILE> tileset;
		for (uint16_t j = 0; j < 200; j++) {
			tileset.push_back(HOUSE);
		}
		mapPreset->mapTiles.push_back(tileset);
	}
	mapPreset->xy[X] = 10;
	mapPreset->xy[Y] = 10;
	mapPreset->mapTiles = {
		{HOUSE, HOUSE, HOUSE, HOUSE, HOUSE, HOUSE, GRASS, GRASS, GRASS, GRASS},
		{HOUSE, ROAD , ROAD , ROAD , ROAD , ROAD , ROAD , ROAD , ROAD , ROAD },
		{HOUSE, ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE, ROAD , GRASS, GRASS},
		{HOUSE, ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE, ROAD , HOUSE, GRASS},
		{HOUSE, ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE},
		{HOUSE, HOUSE, HOUSE, HOUSE, ROAD , HOUSE, HOUSE, HOUSE, HOUSE, HOUSE},
		{WATER, HOUSE, HOUSE, HOUSE, ROAD , ROAD , ROAD , ROAD , ROAD , HOUSE},
		{WATER, WATER, HOUSE, HOUSE, HOUSE, HOUSE, HOUSE, HOUSE, HOUSE, HOUSE},
		{WATER, WATER, WATER, WATER, HOUSE, HOUSE, HOUSE, HOUSE, WATER, WATER},
		{WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
	};
	return mapPreset;
}

std::shared_ptr<MapPreset> MapCreator::map3()
{
	auto mapPreset = std::make_shared<MapPreset>();

	for (uint16_t i = 0; i < 200; i++) {
		std::vector<MAP_TILE> tileset;
		for (uint16_t j = 0; j < 200; j++) {
			tileset.push_back(HOUSE);
		}
		mapPreset->mapTiles.push_back(tileset);
	}
	mapPreset->xy[X] = 10;
	mapPreset->xy[Y] = 10;
	mapPreset->mapTiles = {
		{ROAD , ROAD , ROAD , ROAD , ROAD , ROAD , GRASS, GRASS, GRASS, GRASS},
		{ROAD , HOUSE, HOUSE, HOUSE, HOUSE, HOUSE, HOUSE, GRASS, GRASS, GRASS},
		{ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE, HOUSE, HOUSE, GRASS, GRASS},
		{ROAD , HOUSE, HOUSE, ROAD , HOUSE, ROAD, ROAD , HOUSE, HOUSE, ROAD },
		{ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE, ROAD },
		{ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE, ROAD },
		{ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE, ROAD , HOUSE, HOUSE, ROAD },
		{ROAD , ROAD , ROAD , ROAD , ROAD , HOUSE, ROAD , ROAD , ROAD , ROAD },
		{GRASS, GRASS, GRASS, GRASS, ROAD , ROAD , ROAD , GRASS, GRASS, GRASS},
		{GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
	};
	return mapPreset;
}
