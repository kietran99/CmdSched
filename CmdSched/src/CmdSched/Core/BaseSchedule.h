#pragma once

#include "cspch.h"
#include <BaseTask.h>

namespace CmdSched::Core
{
	class BaseSchedule
	{
	public:
		BaseSchedule();
		BaseSchedule(std::vector<BaseTask>&& tasks);
		~BaseSchedule();

		bool AddTask(BaseTask&& task);
		//bool RemoveTask(std::string name);
		//bool RemoveTask(int idx);
		//bool UpdateTask();
		void ShowAllTasks();
		void FilterTasks();

		friend std::ostream& operator<<(std::ostream& os, const BaseSchedule& sched);
	private:
		std::vector<BaseTask> tasks;
	};
}

