/*
 * Iparameter.hpp
 * Copyright (C) 2018 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include <vector>
#include <string>

struct Args {
	int acArg;
	char shortArg;
	std::string regex;
	const char *longArg;
};

using argsVec = std::vector<Args *>;
using dataVec = std::vector<std::string>;

struct ArgsData {
	Args *identifier;
	dataVec args;
};

using argsDataVec = std::vector<ArgsData *>;

class IParameter
{
	public:
	virtual void option(const char, const char *, const std::string) = 0;
	virtual void option(const char, const char *, int, const std::string) = 0;
	virtual ArgsData *findParameter(char) = 0;
	virtual ArgsData *findParameter(const std::string) = 0;
	virtual argsVec getArgs() const = 0;
	virtual dataVec getData() const = 0;
	virtual std::string getFilename() const = 0;
	virtual void parse() = 0;

	private:
	virtual void checkInArgs(int &) = 0;
};
