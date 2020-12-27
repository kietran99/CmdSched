#pragma once

#include "cspch.h"
#include "BaseTask.h"

#include <optional>


namespace CmdSched::Core
{
	class BaseSchedule
	{
	public:
		BaseSchedule();
		BaseSchedule(std::vector<BaseTask>&& tasks);
		~BaseSchedule();

		void AddTask(BaseTask&& task);
		std::optional<std::out_of_range> DeleteTask(const std::string& name);
		std::optional<std::out_of_range> DeleteTask(const int& idx);
		//bool UpdateTask();
		void ShowAllTasks();
		void FilterTasks();

		friend std::ostream& operator<<(std::ostream& os, const BaseSchedule& sched);
	private:
		std::vector<BaseTask> tasks;
	};
}

