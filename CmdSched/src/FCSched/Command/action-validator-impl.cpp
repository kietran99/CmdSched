#include "cspch.h"

#include "action-validator.h"

#include <functional>

#include "command-executor.h"

namespace Command
{
	std::unordered_set<std::string> availCmdActions =
	{
		{ "add" },
		{ "show" }
	};

	std::unordered_map<std::string, std::function<bool(Core::Schedule&, const std::vector<std::string>)>> availActionsDict =
	{
		{ "add", Add },
		{ "show", Show }
	};

	bool IsValidAction(const std::string& action)
	{
		return availCmdActions.count(action) > 0;
	}
}