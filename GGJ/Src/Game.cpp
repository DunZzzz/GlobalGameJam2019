/*
 * Game.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "Game.hpp"

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unistd.h>

Game::Game(uint16_t x, uint16_t y)
	: mapCreator(std::make_shared<MapCreator>())
{
	size[0] = x;
	size[1] = y;
	srand(time(nullptr));
	tilesCreator = {
		{HOUSE, &House::create},
		{GRASS, &Grass::create},
		{ROAD, &City::create},
		{NONE, &None::create},
		{WATER, &Water::create},
	};
}

Game::~Game()
{
}

void Game::round()
{
	for (auto it1 : currentMap) {
		for (auto it2 : it1) {
			it2->update();
		}
	}
	for (auto it1 : currentMap) {
		for (auto it2 : it1) {
			it2->flush();
		}
	}
}

void Game::init()
{
	ox::SingleResAnim *img = new ox::SingleResAnim();
	img->init("./assets/sky1.png");

	ox::spSprite bg = new ox::Sprite();
	bg->setPosition(0, 0);
	bg->setSize(size[X], size[Y]);
	bg->setResAnim(img);
	bg->attachTo(ox::getStage());

	mapPreset = mapCreator->randomMap();
	currentMap = createMap(mapPreset);
	clock = ox::getStage()->getClock();
	ox::timeMS last;
}

Tiles *Game::createTile(MAP_TILE type, uint16_t *xy) {
	return tilesCreator[type](this, xy);
}

Map Game::createMap(std::shared_ptr<MapPreset> mapPreset)
{
	Map map;

	for (size_t i = 0, size = mapPreset->mapTiles.size(); i != size; i++) {
		std::vector<Tiles*> vecMap;

		for (size_t j = 0, jsize = mapPreset->mapTiles.at(i).size(); j != jsize; ++j) {
			uint16_t pos[XY_SIZE];

			pos[X] = i;
			pos[Y] = j;
			Tiles *tile = createTile(mapPreset->mapTiles.at(i).at(j), pos);
			vecMap.push_back(tile);
		}
		map.push_back(vecMap);
	}
	return map;
}

void Game::draw()
{
}

void Game::termPrintMap()
{
	if (currentMap.empty() == true) {
		std::cout << "No Map Set" << std::endl;
	} else {
		for (auto it1 : currentMap) {
			for (auto it2 : it1) {
				std::cout << (uint16_t)it2->type << " " << std::flush;
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void Game::update()
{
	if ((clock->getTime() - last) > 500) {
		last = clock->getTime();
		round();
	}
}
//termPrintMap();

void Game::destroy(){}
