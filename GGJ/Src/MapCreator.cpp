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
		//		&MapCreator::map2,
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

//std::shared_ptr<MapPreset> MapCreator::map2()
//{
//auto mapPreset = std::make_shared<MapPreset>();

//mapPreset->xy[X] = 5;
//mapPreset->xy[Y] = 5;
//mapPreset->mapTiles = {
//{GRASS, HOUSE, GRASS, HOUSE, GRASS},
//{HOUSE, GRASS, HOUSE, GRASS, HOUSE},
//{GRASS, HOUSE, GRASS, HOUSE, GRASS},
//{HOUSE, GRASS, HOUSE, GRASS, HOUSE},
//{GRASS, HOUSE, GRASS, HOUSE, GRASS},
//};
//return mapPreset;
//}
