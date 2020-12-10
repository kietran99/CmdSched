#include "cspch.h"
#include "AddTaskCommand.h"
#include "DateTime/DefaultDateTimeBuilder.h"
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

	void AddTaskCommand::Execute(Core::BaseSchedule* const& schedule, const std::vector<std::string>& args)
	{			
		Either<InvalidDateTimeError, DateTime* const> maybeDateTime = Builder::Construct(stoi(args[1]), stoi(args[2]));
		maybeDateTime.Map(Builder::SetDay, stoi(args[3]))			
			.Match<CmdState>
			([](InvalidDateTimeError err, CmdState) {},
				[](DateTime* dateTime, CmdState state)
				{
					state.schedule->AddTask({ state.taskName, dateTime });
					state.schedule->ShowAllTasks();
				}, { schedule, args[0] }
				);
			
		//builder->SetDay(stoi(args[3]));
		//builder->SetMonth(stoi(args[4]));
		//builder->SetYear(stoi(args[5]));		
	}

	void Foo(const std::string& s) {}
}
