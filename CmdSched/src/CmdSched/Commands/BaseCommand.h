#pragma once

#include "BaseSchedule.h"

namespace CmdSched::Commands
{
	class BaseCommand
	{
	public:
		virtual ~BaseCommand() {};

		virtual int GetArgsCount() = 0;
		virtual void Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>&) = 0;
	};
}

