#pragma once

#include "BaseCommand.h"

namespace CmdSched::Command
{
	class ShowAllTaskCommand : public BaseCommand
	{
		virtual bool IsExecutable(size_t nArgs) override;
		virtual void Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args) override;
	};
}

