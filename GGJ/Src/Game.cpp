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
}

void Game::destroy(){}
