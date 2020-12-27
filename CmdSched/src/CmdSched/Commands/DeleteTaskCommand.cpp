#include "cspch.h"
#include "DeleteTaskCommand.h"

namespace CmdSched::Commands
{
	bool DeleteTaskCommand::IsExecutable(size_t nArgs)
	{
		return nArgs == 2;
	}

	void DeleteTaskCommand::Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args)
	{
		std::optional<std::out_of_range> err = schedule->DeleteTask(stoi(args[1]));
		if (err.has_value())
		{
			printf("Error: %s\n", err.value().what());
		}
		schedule->ShowAllTasks();
	}
}
