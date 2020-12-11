#include "cspch.h"
#include "AddTaskCommand.h"
#include "DateTime/DateTimeDirector.h"
#include <algorithm>
using namespace CmdSched::Core::DateTime;

namespace CmdSched::Commands
{
	AddTaskCommand::~AddTaskCommand()
	{
		//printf("Destroying Add Task Command\n");
	}
	
	struct CmdState
	{
	public:
		CmdState(Core::BaseSchedule* const& schedule, const std::string& taskName)
			: schedule(schedule), taskName(taskName) {}

		Core::BaseSchedule* const schedule;
		std::string taskName;
	};

	std::vector<std::string> GetDateTimeArgs(const std::vector<std::string>& args)
	{
		std::vector<std::string> dtArgs(args.size() - 1);
		std::copy(args.begin() + 1, args.end(), dtArgs.begin());
		return dtArgs;
	}

	void AddTaskCommand::Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args)
	{		
		const std::string& taskName = args[0];		
		const std::vector<std::string>& dtArgs = GetDateTimeArgs(args);

		auto maybeDateTime = Director::Build(dtArgs);
		maybeDateTime.Match<CmdState>([](InvalidDateTimeError err, CmdState) {},
			[](DateTime* const dateTime, CmdState state)
			{
				state.schedule->AddTask({ state.taskName, dateTime });
				state.schedule->ShowAllTasks();
			},
			{ schedule, taskName });
	}
}
