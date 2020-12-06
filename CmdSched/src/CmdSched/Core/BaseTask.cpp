#include "cspch.h"
#include "BaseTask.h"

namespace CmdSched::Core
{
	BaseTask::BaseTask(const std::string& name, Time&& time)
		: name(name), time(std::move(time)) 
	{
		std::cout << "Constructing Task " << name << "...\n";
	}

	BaseTask::BaseTask(const BaseTask& other)
		: name(other.name), time(other.time)
	{
		std::cout << "Copying Task...\n";
	}

	BaseTask::BaseTask(BaseTask&& other) noexcept
		: name(other.name), time(std::move(other.time))
	{
		std::cout << "Moving Task " << name << "...\n";
	}

	BaseTask::~BaseTask()
	{
		std::cout << "Destroying Task " << name << "...\n";
	}
	
	std::ostream& operator<<(std::ostream& os, const BaseTask& task)
	{
		//os << "o---------------------TASK DATA---------------------o\n";
		
		os << '[' << task.time << ']' << ' ' << task.name;

		//os << "o---------------------------------------------------o\n";

		return os;
	}
}
