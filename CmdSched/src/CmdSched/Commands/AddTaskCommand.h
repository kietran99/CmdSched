#pragma once

#include "BaseCommand.h"

namespace CmdSched::Command
{
	class AddTaskCommand : public BaseCommand
	{
	//public:
		//static std::string cmdName = "add task";
	public:
		virtual ~AddTaskCommand();

		inline virtual bool IsExecutable(size_t nArgs) override { return nArgs == 6 || nArgs == 5 || nArgs == 4 || nArgs == 3; }
		virtual void Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args) override;
	};
}

