#include "cspch.h"
#include "BaseSchedule.h"

namespace CmdSched::Core
{
	std::ostream& operator<<(std::ostream& os, const BaseSchedule& sched)
	{
		os << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		os << "o-------------------------SCHEDULE-------------------------o\n";
		size_t len = sched.tasks.size();
		for (int i = 0; i < len; i++)
		{
			os << sched.tasks[i] << std::endl;
		}
		os << "o----------------------------------------------------------o\n";
		os << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		return os;
	}

	BaseSchedule::BaseSchedule()
		//: tasks({})
	{
		std::cout << "Constructing Schedule...\n";
	}

	BaseSchedule::BaseSchedule(std::vector<BaseTask>&& tasks)
		//: tasks(std::move(tasks))
	{
	}

	BaseSchedule::~BaseSchedule()
	{
		/*for (size_t i = 0, len = tasks.size(); i < len; i++)
		{
			delete tasks[i];
			tasks[i] = nullptr;
		}*/
	}

	bool BaseSchedule::AddTask(BaseTask&& task)
	{
		tasks.push_back(std::move(task));
		return true;
	}

	/*void ShowTaskInfo(const BaseTask& task)
	{
		std::cout << task << std::endl;
	}*/

	void BaseSchedule::ShowAllTasks()
	{
		std::cout << this << std::endl;
	}	

	void BaseSchedule::FilterTasks()
	{
	}
}
