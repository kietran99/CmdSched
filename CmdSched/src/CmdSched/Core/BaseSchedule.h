#pragma once

#include "cspch.h"
#include "BaseTask.h"
#include "Errors/InvalidTaskName.h"

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
		Functional::Type::Optional<CmdSched::Command::Error::InvalidTaskName> DeleteTask(const std::string& name);
		Functional::Type::Optional<std::out_of_range> DeleteTask(const int& idx);
		//bool UpdateTask();
		void ShowAllTasks();
		void FilterTasks();

		friend std::ostream& operator<<(std::ostream& os, const BaseSchedule& sched);
	private:
		std::vector<BaseTask> tasks;
	};
}

