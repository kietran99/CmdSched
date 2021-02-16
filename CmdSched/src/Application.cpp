#include "cspch.h"

#include "input-reader.h"
#include "schedule.h"
#include "command-executor.h"

class Application
{
public:
	Application()
		: schedule({}) 
	{
		InitTestData();
		Run();
	}

	void Run()
	{
		while (true)
		{
			std::cout << "Enter Command: ";
			auto maybeCmdData = Command::ReadInput(std::cin);
			auto err = std::get_if<InvalidCommandError>(&maybeCmdData);

			if (err)
			{
				std::cout << err->msg << std::endl;
				continue;
			}

			auto cmdData = std::get_if<Command::CommandData>(&maybeCmdData);
			Command::Execute(cmdData->executor, schedule, cmdData->values);

			
				Command::Show(schedule, {});
			
		}
	}

private:
	void InitTestData()
	{
		Command::Add(schedule, { "Clean the House", "15", "02", "2021" });
		Command::Show(schedule, {});
		Command::Add(schedule, { "Write some Code", "20", "04", "2021" });
		Command::Show(schedule, {});
		Command::Add(schedule, { "Eat Chocolate", "29", "02", "2024" });
		Command::Show(schedule, {});
	}

private:
	Core::Schedule schedule;
};

int main()
{
	Application *app = new Application();
	std::cin.get();
}