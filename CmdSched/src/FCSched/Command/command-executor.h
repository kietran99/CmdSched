#pragma once

#include "cspch.h"

#include "schedule.h"
#include "fcsched-errors.h"

namespace Command
{
	using ArgValues = const std::vector<std::string>;

	bool Execute(
		std::function<bool(Core::Schedule& schedule, std::vector<std::string>)> fn, 
		Core::Schedule& schedule, 
		ArgValues values);
	bool Show(Core::Schedule& schedule, ArgValues values);
	bool Exit(Core::Schedule& schedule, ArgValues values);
	bool Refresh(Core::Schedule& schedule, ArgValues values);
	bool Add(Core::Schedule& schedule, ArgValues values);
	bool RemoveName(Core::Schedule& schedule, ArgValues values);
	bool RemoveAt(Core::Schedule& schedule, ArgValues values);
}