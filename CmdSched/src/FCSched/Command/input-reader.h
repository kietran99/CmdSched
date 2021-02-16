#pragma once

#include "cspch.h"

#include "action-validator.h"
#include "command-data.h"
#include "fcsched-errors.h"

namespace Command
{
	constexpr int MAX_ARGS = 10;

	using ArgList = std::vector<std::string>;

	// Need rework on multi-syllable command actions
	const std::variant<InvalidCommandError, CommandData> ReadInput(std::istream& input);
	void LogInputArgs(const ArgList &args);
}