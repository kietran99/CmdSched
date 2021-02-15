#pragma once

#include "cspch.h"

#include "schedule.h"
#include "fcsched-errors.h"

namespace Command
{
	using ArgValues = const std::vector<std::string>;

	bool Show(Core::Schedule& schedule, ArgValues values);
	bool Add(Core::Schedule& schedule, const std::vector<std::string> values);
	bool RemoveName(Core::Schedule& schedule, const std::vector<std::string> values);
	bool RemoveAt(Core::Schedule& schedule, const std::vector<std::string> values);
}