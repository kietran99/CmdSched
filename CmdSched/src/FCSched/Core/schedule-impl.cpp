#include "cspch.h"

#include "schedule.h"

namespace Core
{
	void Schedule::AddTask(Task&& task)
	{
		taskList.push_back(std::move(task));
	}

	bool Schedule::RemoveName(const std::string& name)
	{
		auto removePosIter = FindByName(name);

		if (removePosIter == taskList.end())
		{
			return false;
		}

		taskList.erase(removePosIter);

		return true;
	}

	bool Schedule::RemoveAt(int idx)
	{
		if (IsIndexOutOfRange(idx))
		{
			return false;
		}

		taskList.erase(taskList.begin() + idx);

		return true;
	}

	bool Schedule::UpdateNameByName(const std::string& oldName, const std::string& newName)
	{
		auto updatePosIter = FindByName(oldName);

		if (updatePosIter == taskList.end())
		{
			return false;
		}

		taskList[updatePosIter - taskList.begin()].name = newName;

		return true;
	}

	bool Schedule::UpdateTimeByName(const std::string& name, u_short day, u_short month, u_short year)
	{
		auto updatePosIter = FindByName(name);

		if (updatePosIter == taskList.end())
		{
			return false;
		}

		auto idx = updatePosIter - taskList.begin();
		taskList[idx].day = day;
		taskList[idx].month = month;
		taskList[idx].year = year;

		return true;
	}

	bool Schedule::UpdateNameByIdx(int idx, const std::string& newName)
	{
		if (IsIndexOutOfRange(idx))
		{
			return false;
		}

		taskList[idx].name = newName;

		return true;
	}

	bool Schedule::UpdateTimeByIdx(int idx, u_short day, u_short month, u_short year)
	{
		if (IsIndexOutOfRange(idx))
		{
			return false;
		}

		taskList[idx].day = day;
		taskList[idx].month = month;
		taskList[idx].year = year;

		return true;
	}

	std::vector<Task>::const_iterator Schedule::FindByName(const std::string& name)
	{
		return std::find_if(taskList.begin(), taskList.end(), [&](const Task& task) { return task.name == name; });
	}

	bool Schedule::IsIndexOutOfRange(int idx)
	{
		return idx < 0 || idx >= taskList.size();
	}

	void Schedule::Show() const
	{
		int cnt = 0;

		for (auto& task : taskList)
		{
			std::cout << cnt << ". ";
			task.Log();
			cnt++;
		}

		std::cout << std::endl;
	}
}