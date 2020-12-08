#include "cspch.h"
#include "AddTaskCommand.h"

namespace CmdSched::Commands
{
	AddTaskCommand::~AddTaskCommand()
	{
		//printf("Destroying Add Task Command\n");
	}

	void AddTaskCommand::Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args)
	{
		schedule->AddTask({ args[0], {stoi(args[1]), stoi(args[2]), stoi(args[3]),
						stoi(args[4]), stoi(args[5]) } });
		schedule->ShowAllTasks();
	}
}
