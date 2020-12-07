#pragma once

#include "BaseCommand.h"

namespace CmdSched::Commands
{
	class NoCommand : public BaseCommand
	{
	public:
		NoCommand();

		virtual int GetArgsCount() override { return 0; }
		virtual void Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args) override;
	};
}

