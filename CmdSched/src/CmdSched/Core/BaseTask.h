#pragma once

#include "cspch.h"
#include "Time.h"

namespace CmdSched::Core
{
	class BaseTask
	{
	public:
		BaseTask(const std::string& name, Time&& time);
		BaseTask(const BaseTask& other);
		BaseTask(BaseTask&& other) noexcept;
		~BaseTask();

		friend std::ostream& operator<<(std::ostream& os, const BaseTask& task);
	private:
		std::string name;
		Time time;
	};
}

