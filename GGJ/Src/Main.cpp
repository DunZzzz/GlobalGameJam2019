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
	oxygine::ObjectBase::__startTracingLeaks();
	oxygine::core::init_desc desc;
	desc.title = "Oxygine Application";

	desc.w = game->size[0];
	desc.h = game->size[1];

	oxygine::core::init(&desc);

	oxygine::Stage::instance = new oxygine::Stage();
	oxygine::Point size = oxygine::core::getDisplaySize();
	oxygine::getStage()->setSize(size);

	oxygine::DebugActor::show();

	game->init();
	bool done = false;
	while (done == false)
	{
		done = oxygine::core::update();
		game->update();
		oxygine::getStage()->update();

		if (oxygine::core::beginRendering())
		{
			oxygine::Color clearColor(32, 32, 32, 255);
			oxygine::Rect viewport(oxygine::Point(0, 0), oxygine::core::getDisplaySize());
			oxygine::getStage()->render(clearColor, viewport);
			oxygine::core::swapDisplayBuffers();
		}
	}
	oxygine::ObjectBase::dumpCreatedObjects();
	game->destroy();
	//renderer.cleanup();
	oxygine::core::release();
	oxygine::ObjectBase::dumpCreatedObjects();
	oxygine::ObjectBase::__stopTracingLeaks();
}

int main(const int, char const**)
{
	std::shared_ptr<Game> game = std::make_shared<Game>(800, 800);
	run(game);
	return 0;
}
