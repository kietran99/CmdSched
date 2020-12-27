#include "cspch.h"
#include "DeleteTaskCommand.h"

namespace CmdSched::Command
{
	bool DeleteTaskCommand::IsExecutable(size_t nArgs)
	{
		return nArgs == 2;
	}

	void DeleteTaskCommand::Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args)
	{
		if (args[0] == "i")
		{
			Functional::Type::Optional<std::out_of_range> result = schedule->DeleteTask(stoi(args[1]));
			result.Match([](std::out_of_range err) { printf("Error: %s\n", err.what()); });
			return;
		}
		
		if (args[0] == "n")
		{
			Functional::Type::Optional<Error::InvalidTaskName> result = schedule->DeleteTask(args[1]);
			result.Match([](Error::InvalidTaskName err) { std::cout << err.GetMessage() << std::endl; });
			return;
		}

		printf("Error: Invalid Command\n");
	}
}
