#pragma once

#include "cspch.h"

namespace CmdSched::Core
{	
	struct Time
	{
		//enum WeekDays { MON, TUE, WED, THU, FRI, SAT, SUN};

		Time(int hour, int min, int sec, int day, int month, int year);
		Time(const Time& other);
		Time(Time&& other) noexcept;
		~Time();

		friend std::ostream& operator<<(std::ostream& os, const Time& time);

		int hour, min, sec, day, month, year;
	};
}

