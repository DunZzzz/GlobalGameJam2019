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
	};

	return ((*this).*(pool.at(rand() % pool.size())))();
}

std::shared_ptr<MapPreset> MapCreator::map1()
{
	auto mapPreset = std::make_shared<MapPreset>();

	mapPreset->xy[X] = 5;
	mapPreset->xy[Y] = 5;
	mapPreset->mapTiles = {
		{GRASS, HOUSE, GRASS, HOUSE, GRASS},
		{HOUSE, GRASS, HOUSE, GRASS, HOUSE},
		{GRASS, HOUSE, GRASS, HOUSE, GRASS},
		{HOUSE, GRASS, HOUSE, GRASS, HOUSE},
		{GRASS, HOUSE, GRASS, HOUSE, GRASS},
	};
	return mapPreset;
}

std::shared_ptr<MapPreset> MapCreator::map2()
{
	auto mapPreset = std::make_shared<MapPreset>();

	mapPreset->xy[X] = 5;
	mapPreset->xy[Y] = 5;
	mapPreset->mapTiles = {
		{GRASS, HOUSE, GRASS, HOUSE, GRASS},
		{HOUSE, GRASS, HOUSE, GRASS, HOUSE},
		{GRASS, HOUSE, GRASS, HOUSE, GRASS},
		{HOUSE, GRASS, HOUSE, GRASS, HOUSE},
		{GRASS, HOUSE, GRASS, HOUSE, GRASS},
	};
	return mapPreset;
}