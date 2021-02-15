#pragma once

#include "cspch.h"

struct InvalidCommandError
{
	const char* msg = "Invalid Command!";
};

struct MismatchArgumentsError
{
	const char* msg = "The number of Arguments does not match!";
};

struct InvalidArgumentType
{
	const char* msg = "Invalid Argument Type!";
};

