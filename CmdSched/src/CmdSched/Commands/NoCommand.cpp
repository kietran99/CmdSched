#include "cspch.h"
#include "NoCommand.h"

namespace CmdSched::Command
{
	NoCommand::NoCommand() {}

	void NoCommand::Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args) {}
}
