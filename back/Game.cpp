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

Game::Game()
	: mapCreator(std::make_shared<MapCreator>())
{
	srand(time(nullptr));
}

Game::~Game()
{
}

void Game::round()
{
	MapTiles newMap;
	int x = -1;

	std::cout << "nbr de maisons en feu autour" << std::endl;
	while (++x < currentMap->mapTiles.size()){
		int y = -1;
		std::vector<MAP_TILE> tmp2;
		newMap.push_back(tmp2);
		while (++y < currentMap->mapTiles.at(x).size()){
			int tmp = 0;
			if (x > 0 && currentMap->mapTiles.at(x - 1).at(y) == BURNING_HOUSE)
				tmp++;
			if (x < (currentMap->mapTiles.size() - 1) && currentMap->mapTiles.at(x + 1).at(y) == BURNING_HOUSE)
				tmp++;
			if (y > 0 && currentMap->mapTiles.at(x).at(y - 1) == BURNING_HOUSE)
				tmp++;
			if (y < (currentMap->mapTiles.at(x).size() - 1) && currentMap->mapTiles.at(x).at(y + 1) == BURNING_HOUSE)
				tmp++;
			if (x > 0 && y > 0 && currentMap->mapTiles.at(x - 1).at(y - 1) == BURNING_HOUSE)
				tmp++;
			if (x < (currentMap->mapTiles.size() - 1) && y > 0 && currentMap->mapTiles.at(x + 1).at(y - 1) == BURNING_HOUSE)
				tmp++;
			if (x > 0 && y < (currentMap->mapTiles.at(x).size() - 1) && currentMap->mapTiles.at(x - 1).at(y + 1) == BURNING_HOUSE)
				tmp++;
			if (x < (currentMap->mapTiles.size() - 1) && y < (currentMap->mapTiles.at(x).size() - 1) && currentMap->mapTiles.at(x + 1).at(y + 1) == BURNING_HOUSE)
				tmp++;
			if (tmp == 3 && currentMap->mapTiles.at(x).at(y) == HOUSE)
				newMap.at(x).push_back(BURNING_HOUSE);
			else if ((tmp > 3 || tmp < 2) && currentMap->mapTiles.at(x).at(y) == BURNING_HOUSE)
				newMap.at(x).push_back(HOUSE);
			else
				newMap.at(x).push_back(currentMap->mapTiles.at(x).at(y));
		}
	}
	currentMap->mapTiles = newMap;
}

void Game::init()
{
	currentMap = mapCreator->randomMap();
}

void Game::draw()
{
}

void Game::termPrintMap()
{
	if (currentMap == nullptr) {
		std::cout << "No Map Set" << std::endl;
	} else {
		for (auto it1 : currentMap->mapTiles) {
			for (auto it2 : it1) {
				std::cout << (uint16_t)it2 << " " << std::flush;
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void Game::update()
{
	termPrintMap();
	round();
}

void Game::destroy(){}
