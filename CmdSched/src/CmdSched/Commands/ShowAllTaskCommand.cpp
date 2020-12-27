#include "cspch.h"
#include "ShowAllTaskCommand.h"

bool CmdSched::Command::ShowAllTaskCommand::IsExecutable(size_t nArgs)
{
	return nArgs == 0;
}

void CmdSched::Command::ShowAllTaskCommand::Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args)
{
	schedule->ShowAllTasks();
}
