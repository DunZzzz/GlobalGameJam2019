/*
 * Parameter.cpp
 * Copyright (C) 2018 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cstring>
#include <regex>

#include "parameter.hpp"

Parameter::Parameter(int _ac, const char **_av)
	: ac(_ac - 1)
	, av(_av + 1)
	, filename(_av[0])
{
}

Parameter::~Parameter()
{
	argsDataVec::iterator i;

	for (i = argsData.begin(); i != argsData.end(); i++)
		delete *i;
	for (argsVec::iterator j = args.begin(); j != args.end(); j++)
		delete *j;
}

void Parameter::option(const char c,
					   const char *str,
					   int nArg,
					   const std::string regex)
{
	Args *newArgs = new Args;

	newArgs->acArg = nArg;
	newArgs->shortArg = c;
	newArgs->longArg = str;
	newArgs->regex = regex;
	args.push_back(newArgs);
}

void Parameter::option(const char c,
					   const char *str,
					   const std::string regex)
{
	this->option(c, str, 1, regex);
}

std::string Parameter::getFilename() const
{
	return this->filename;
}

argsVec Parameter::getArgs() const
{
	return this->args;
}

dataVec Parameter::getData() const
{
	return this->data;
}

void Parameter::checkDeeperInArgs(Args *args, int &i, ArgsData *moving)
{
	for (int ite = 0; ite < args->acArg; ite++) {
		i++;
		if (av[i] == NULL) {
			std::stringstream t;

			t << "Not enough parameter for '" << args->shortArg << "'";
			throw err::excep(t.str());
		}
		if (args->regex != ""
			&& !std::regex_match(av[i], std::regex(args->regex))) {
			std::stringstream t;

			t << "Argument n°" << i << " didn't match regular expression";
			throw err::excep(t.str());
		}
		moving->args.push_back(av[i]);
	}
}

void Parameter::checkInArgs(int &i)
{
	ArgsData *moving;

	for (argsVec::iterator j = args.begin(); j != args.end(); j++) {
		if (av[i][1] == (*j)->shortArg
			|| !strcmp(av[i] + 2, (*j)->longArg)) {
			moving = new ArgsData;
			moving->identifier = *j;
			this->checkDeeperInArgs(*j, i, moving);
			argsData.push_back(moving);
			return;
		}
	}
	std::stringstream t;

	t << "Unknow Argument '" << av[i] << "'";
	throw err::excep(t.str());
}

std::string Parameter::findData(size_t pos)
{
	if (pos > data.size())
		return NULL;
	return data.at(pos);
}

ArgsData *Parameter::findParameter(char c)
{
	argsDataVec::iterator i;

	for (i = argsData.begin(); i != argsData.end(); i++) {
		if ((*i)->identifier->shortArg == c) {
			return *i;
		}
	}
	return NULL;
}

ArgsData *Parameter::findParameter(const std::string str)
{
	argsDataVec::iterator i;

	for (i = argsData.begin(); i != argsData.end(); i++) {
		if ((*i)->identifier->longArg == str) {
			return *i;
		}
	}
	return NULL;
}

void Parameter::parse()
{
	for (int i = 0; i < ac; i++) {
		if (!strncmp(av[i], "--", 2) || av[i][0] == '-') {
			this->checkInArgs(i);
		} else {
			data.push_back(std::string(av[i]));
		}
	}
}
