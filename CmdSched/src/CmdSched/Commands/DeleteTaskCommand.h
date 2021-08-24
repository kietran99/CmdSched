#pragma once

#include "BaseCommand.h"

namespace CmdSched::Command
{
	class DeleteTaskCommand : public BaseCommand
	{
	public:
		//static const std::string cmdName = "del task";

		virtual bool IsExecutable(size_t nArgs) override;
		virtual void Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args) override;
	};
}

