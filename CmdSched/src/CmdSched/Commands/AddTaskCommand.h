#pragma once

#include "BaseCommand.h"

namespace CmdSched::Commands
{
	class AddTaskCommand : public BaseCommand
	{
	public:
		virtual ~AddTaskCommand();

		inline virtual int GetArgsCount() override { return 7; }
		virtual void Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args) override;
	};
}

