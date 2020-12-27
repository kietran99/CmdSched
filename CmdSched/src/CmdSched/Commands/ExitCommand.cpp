#include "cspch.h"
#include "ExitCommand.h"

namespace CmdSched::Command
{	
	void ExitCommand::Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args)
	{
		exit(0);
	}
}