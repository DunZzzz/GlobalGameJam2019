/*
 * Game.hpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

class Game;

class MapCreator;
struct MapPreset;

#include "MapCreator.hpp"
#include "Tiles.hpp"
#include "House.hpp"
#include "Grass.hpp"
#include "Water.hpp"
#include "City.hpp"
#include "None.hpp"
#include "Oxygine.hpp"

#include <memory>
#include <unordered_map>

using Map = std::vector<std::vector<Tiles*>>;

class Game
{
	public:
		Game(uint16_t x, uint16_t y);
		virtual ~Game();
		void init();
		void initGame();
		void update();
		void setMenu();
		void destroy();
		Tiles *createTile(MAP_TILE type, uint16_t *xy);
		Map createMap(std::shared_ptr<MapPreset>);
		void round();
		void buttonClicked(ox::Event*);

	private:
		void draw();
		void termPrintMap();

	public:
		ox::spSprite menu;
		ox::spClock clock;
		Map currentMap;
		ox::timeMS last;
		std::shared_ptr<MapPreset> mapPreset;
		std::shared_ptr<MapCreator> mapCreator;
		std::unordered_map<MAP_TILE, Tiles *(*)(Game *, uint16_t *)> tilesCreator;
		uint16_t size[2];
};

