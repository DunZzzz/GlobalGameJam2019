/*
 * Exception.cpp
 * Copyright (C) 2018 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include "Exception.hpp"

#include <cstring>

err::ExceptionThrower::ExceptionThrower(const std::string &message, uint32_t line, const std::string &function, const std::string &file)
    : message(message)
    , function(function)
    , file(strdup(file.c_str()))
    , line(line)
{
	if (this->file == nullptr)
		this->file = (char *)"";
}

err::ExceptionThrower::ExceptionThrower(const ExceptionThrower &)
{
}

err::ExceptionThrower::~ExceptionThrower()
{
	free(file);
}

err::ExceptionThrower &err::ExceptionThrower::operator=(const ExceptionThrower &copy)
{
	this->line = (uint32_t)-1;
	this->message = copy.message;
	return *this;
}

const char *err::ExceptionThrower::what() const noexcept
{
	if (line != (uint32_t)-1) {
		std::string basepath = basename(file);
		if (message != "")
			return strdup((basepath + " l." + std::to_string(line) + ": " + function + ": " + message).c_str());
		else
			return strdup((basepath + " l." + std::to_string(line) + ": " + function).c_str());
	} else if (message != "") {
		return strdup((std::string("Error: ") + message).c_str());
	}
	return "Error.";
}
