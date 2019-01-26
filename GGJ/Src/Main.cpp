/*
 * Main.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "Main.hpp"

#include <memory>

void run(std::shared_ptr<Game> game)
{
	ox::ObjectBase::__startTracingLeaks();
	ox::core::init_desc desc;
	desc.title = "Oxygine Application";

	desc.w = game->size[0];
	desc.h = game->size[1];

	ox::core::init(&desc);

	ox::Stage::instance = new ox::Stage();
	ox::Point size = ox::core::getDisplaySize();
	ox::getStage()->setSize(size);

	ox::DebugActor::show();

	game->init();
	bool done = false;
	while (done == false)
	{
		done = ox::core::update();
		game->update();
		ox::getStage()->update();

		if (ox::core::beginRendering())
		{
			ox::Color clearColor(32, 32, 32, 255);
			ox::Rect viewport(ox::Point(0, 0), ox::core::getDisplaySize());
			ox::getStage()->render(clearColor, viewport);
			ox::core::swapDisplayBuffers();
		}
	}
	ox::ObjectBase::dumpCreatedObjects();
	game->destroy();
	//renderer.cleanup();
	ox::core::release();
	ox::ObjectBase::dumpCreatedObjects();
	ox::ObjectBase::__stopTracingLeaks();
}

int main(const int, char const**)
{
	std::shared_ptr<Game> game = std::make_shared<Game>(800, 800);
	run(game);
	return 0;
}
