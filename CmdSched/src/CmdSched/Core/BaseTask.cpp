#include "cspch.h"
#include "BaseTask.h"

namespace CmdSched::Core
{
	BaseTask::BaseTask(const std::string& name, DateTime::DateTime&& time)
		: name(name), dateTime(std::move(time)) 
	{
		//std::cout << "Constructing Task " << name << "...\n";
	}

	BaseTask::BaseTask(const std::string& name, DateTime::DateTime* time)	
		: name(name), dateTime(*time){}

	/*BaseTask::BaseTask(std::string name, DateTime::DateTime&& time)
		: name(name), time(std::move(time)) {}*/

	BaseTask::BaseTask(const BaseTask& other)
		: name(other.name), dateTime(other.dateTime)
	{
		//std::cout << "Copying Task...\n";
	}

	BaseTask::BaseTask(BaseTask&& other) noexcept
		: name(other.name), dateTime(std::move(other.dateTime))
	{
		//std::cout << "Moving Task " << name << "...\n";
	}

	BaseTask::~BaseTask()
	{
		//std::cout << "Destroying Task " << name << "...\n";
	}

	BaseTask& BaseTask::operator=(BaseTask&& other) noexcept
	{
		if (this != &other)
		{
			name = other.name;
			dateTime = std::move(other.dateTime);

			other.name = "";
		}

		return *this;
	}

	std::string BaseTask::GetName()
	{
		return name;
	}
	
	std::ostream& operator<<(std::ostream& os, const BaseTask& task)
	{		
		os << '[' << task.dateTime << ']' << ' ' << task.name;
		return os;
	}
}
