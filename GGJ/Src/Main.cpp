/*
 * Main.cpp
 * Copyright (C) 2019 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "Main.hpp"

#include "ox/oxygine.hpp"
#include "ox/Stage.hpp"
#include "ox/DebugActor.hpp"

Main::Main()
{
}

Main::~Main()
{
}

void run()
{
	oxygine::ObjectBase::__startTracingLeaks();
	oxygine::core::init_desc desc;
	desc.title = "Oxygine Application";

	desc.w = 960;
	desc.h = 640;

	//example_preinit();
	oxygine::core::init(&desc);

	// Create the stage. Stage is a root node for all updateable and drawable objects
	oxygine::Stage::instance = new oxygine::Stage();
	oxygine::Point size = oxygine::core::getDisplaySize();
	oxygine::getStage()->setSize(size);

	oxygine::DebugActor::show();

	//example_init();
	bool done = false;
	while (done == false)
	 {
		done = oxygine::core::update();
		//example_update();
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
	//example_destroy();
	//renderer.cleanup();
	oxygine::core::release();
	oxygine::ObjectBase::dumpCreatedObjects();
	oxygine::ObjectBase::__stopTracingLeaks();
}

int main(const int, char const**)
{
	run();
	return 0;
}
