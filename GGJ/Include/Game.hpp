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

#include <memory>

class Game
{
	public:
		Game();
		virtual ~Game();
		void init();
		void update();
		void destroy();

	private:
		void draw();
		void termPrintMap();

	private:
		std::shared_ptr<MapPreset> currentMap;
		std::shared_ptr<MapCreator> mapCreator;
};

