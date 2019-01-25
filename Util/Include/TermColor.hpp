/*
 * TermColor.hpp
 * Copyright (C) 2018 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include <ostream>

enum TermColor {
	FG_RED = 31,
	FG_GREEN = 32,
	FG_BLUE = 34,
	FG_DEFAULT = 39,
	BG_RED = 41,
	BG_GREEN = 42,
	BG_BLUE = 44,
	BG_DEFAULT = 49
};

std::ostream &operator<<(std::ostream &os, const TermColor &code);
