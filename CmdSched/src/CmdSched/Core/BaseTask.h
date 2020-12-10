#pragma once

#include "cspch.h"
#include "DateTime/DateTime.h"

namespace CmdSched::Core
{
	class BaseTask
	{
	public:
		BaseTask(const std::string& name, DateTime::DateTime&& time);
		BaseTask(const std::string& name, DateTime::DateTime* time);
		BaseTask(std::string name, DateTime::DateTime&& time);
		BaseTask(const BaseTask& other);
		BaseTask(BaseTask&& other) noexcept;
		~BaseTask();

		friend std::ostream& operator<<(std::ostream& os, const BaseTask& task);
	private:
		std::string name;
		DateTime::DateTime time;
	};
}

