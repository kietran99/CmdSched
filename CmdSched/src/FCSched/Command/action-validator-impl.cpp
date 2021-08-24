#include "cspch.h"

#include "action-validator.h"

#include <unordered_map>

#include "command-executor.h"

namespace Command
{
	std::unordered_map<std::string, std::function<bool(Core::Schedule&, const std::vector<std::string>)>> availActionsDict =
	{
		{ "add", Add },
		{ "show", Show },
		{ "exit", Exit },
		{ "remove name", RemoveName },
		{ "remove at", RemoveAt }
	};

	std::optional<
		std::function<bool(Core::Schedule&, const std::vector<std::string>)>> 
		TryGetAction(const std::string& actionAsStr)
	{
		auto searchRes = availActionsDict.find(actionAsStr);

		if (searchRes != availActionsDict.end())
		{
			return searchRes->second;
		}
		else
		{
			return std::nullopt;
		}
	}
}