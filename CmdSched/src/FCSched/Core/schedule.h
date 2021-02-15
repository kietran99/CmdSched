#pragma once

#include "cspch.h"

#include "task.h"

namespace Core
{
	class Schedule
	{
	public:
		Schedule()
			: taskList({}) {}

		void Show() const;
		void AddTask(Task&& task);
		bool RemoveName(const std::string& name);
		bool RemoveAt(int idx);
		bool UpdateNameByName(const std::string& oldName, const std::string& newName);
		bool UpdateTimeByName(const std::string& name, u_short day, u_short month, u_short year);
		bool UpdateNameByIdx(int idx, const std::string& newName);
		bool UpdateTimeByIdx(int idx, u_short day, u_short month, u_short year);

	private:
		std::vector<Task>::const_iterator FindByName(const std::string& name);
		bool IsIndexOutOfRange(int idx);

	private:
		std::vector<Task> taskList;
	};
}