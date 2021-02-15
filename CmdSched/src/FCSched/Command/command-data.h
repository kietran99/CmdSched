#pragma once

#include "cspch.h"

namespace Command
{
	struct CommandData
	{
		CommandData(std::string action, std::vector<std::string> values)
			: action(action), values(values) {}

		std::vector<std::string> values;
		//std::vector<std::string> flags;
		std::string action;

		friend std::ostream& operator<<(std::ostream& os, const CommandData& cmdData)
		{
			os << std::endl << "Action: " << cmdData.action << std::endl << "Values: ";
			for (auto& v : cmdData.values) os << v << " ";
			os << std::endl;
			return os;
		}
	};
}