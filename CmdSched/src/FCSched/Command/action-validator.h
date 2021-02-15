#pragma once

#include "cspch.h"

#include <unordered_set>

#include "command-executor.h"

namespace Command
{
	bool IsValidAction(const std::string& action);
}