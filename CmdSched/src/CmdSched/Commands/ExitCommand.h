#pragma once

#include "BaseCommand.h"

namespace CmdSched::Command
{
	class ExitCommand : public BaseCommand
	{
	public:
		//static const std::string cmdName = "exit";

		virtual bool IsExecutable(size_t nArgs) override { return nArgs == 0; }

		virtual void Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args) override;
	};
}

