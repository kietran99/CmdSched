#pragma once

#include "cspch.h"

#include "schedule.h"

namespace Command
{
	struct CommandData
	{
		CommandData(
			std::function<bool(Core::Schedule&, const std::vector<std::string>)> executor, 
				std::vector<std::string> values)
			: executor(executor), values(values) {}

		std::vector<std::string> values;
		//std::vector<std::string> flags;
		std::function<bool(Core::Schedule&, const std::vector<std::string>)> executor;

		friend std::ostream& operator<<(std::ostream& os, const CommandData& cmdData)
		{
			os << std::endl << "Values: ";
			for (auto& v : cmdData.values) os << v << " ";
			os << std::endl;
			return os;
		}
	};
}