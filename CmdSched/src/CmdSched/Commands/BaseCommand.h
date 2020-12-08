#pragma once

#include "BaseSchedule.h"

namespace CmdSched::Commands
{
	class BaseCommand
	{
	public:
		virtual ~BaseCommand() {};

		virtual bool IsExecutable(size_t nArgs) = 0;
		void Resolve(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args)
		{
			printf("Validating Command...\n");

			if (!IsExecutable(args.size()))
			{
				printf("The number of arguments does not match\n");
				return;
			}

			Execute(schedule, args);
		}
	protected:
		virtual void Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args) = 0;
	};
}

