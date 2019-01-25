/*
 * parameter.hpp
 * Copyright (C) 2018 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include "Iparameter.hpp"
#include "Exception.hpp"

class Parameter : virtual public IParameter
{
	public:
	Parameter(int, const char **);
	~Parameter();
	void option(const char, const char *, const std::string);
	void option(const char, const char *, int, const std::string);
	std::string findData(size_t);
	ArgsData *findParameter(char);
	ArgsData *findParameter(const std::string);
	std::string getFilename() const;
	argsVec getArgs() const;
	dataVec getData() const;
	void parse();

	private:
	void checkDeeperInArgs(Args *, int &, ArgsData *moving);
	void checkInArgs(int &);

	private:
	argsDataVec argsData;
	argsVec args;
	dataVec data;
	int ac;
	const char **av;
	std::string filename;
};
