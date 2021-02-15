#pragma once

#include "cspch.h"

namespace Core
{
	struct Task
	{
		Task()
			: name("Default"), day(1), month(1), year(2021){}

		Task(std::string name, u_short day, u_short month, u_short year)
			: name(name), day(day), month(month), year(year) {
			printf("Task - Created: %s\n", name.c_str());
		}

		Task(const Task& that)
			: name(that.name), day(that.day), month(that.month), year(that.year) {
			printf("Task - Copied: %s\n", name.c_str());
		}

		Task(Task&& that) noexcept
			: name(that.name), day(that.day), month(that.month), year(that.year) 
		{
			printf("Task - Moved: %s\n", name.c_str());
			that.name.clear();
			that.day = 0;
			that.month = 0;
			that.year = 0;
		}

		Task& operator=(Task&& that) noexcept
		{
			printf("Task - Moved: %s\n", name.c_str());
			
			if (this != &that)
			{
				name.clear();
				name = that.name;
				day = that.day;
				month = that.month;
				year = that.year;

				that.name.clear();
				that.day = 0;
				that.month = 0;
				that.year = 0;
			}

			return *this;
		}

		~Task() { printf("Task - Destroyed: %s\n", name.empty() ? "EMPTY" : name.c_str()); }

		void Log() const
		{
			auto FormatNum = [](const int& num) { return (num < 10 ? "0" : "") + std::to_string(num); };
			printf("\033[0;36m");
			printf("[%s-%s-%s] %s\n", FormatNum(day).c_str(), FormatNum(month).c_str(), FormatNum(year).c_str(), name.c_str());
			printf("\033[0;37m");
		}

		std::string name;
		u_short day, month, year;
	};
}

