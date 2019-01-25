/*
 * Exception.hpp
 * Copyright (C) 2018 emilien <emilien@emilien-pc>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include <exception>
#include <string>
#include <sstream>
#include <stdint.h>
#include <libgen.h>

namespace err
{

	class ExceptionThrower : public std::exception
	{
		public:
		ExceptionThrower(const std::string &message = "", uint32_t line = (uint32_t)-1, const std::string &function = "", const std::string &file = "");
		ExceptionThrower(const ExceptionThrower &);
		~ExceptionThrower();
		ExceptionThrower &operator=(const ExceptionThrower &);
		virtual const char *what() const noexcept override;

		public:
		std::string message;
		const std::string function;
		char *file;
		uint32_t line;
	};

#define excep(x) ExceptionThrower(x, __LINE__, __PRETTY_FUNCTION__, __FILE__)
#define warning(x) std::cerr << ExceptionThrower(x, __LINE__, __PRETTY_FUNCTION__, __FILE__).what() << std::endl;

}
