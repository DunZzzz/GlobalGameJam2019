/*
 * Color.cpp
 * Copyright (C) 2018 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "TermColor.hpp"

std::ostream &operator<<(std::ostream &os, const TermColor &code) {
		return os << "\033[" << (int)code << "m";
}
