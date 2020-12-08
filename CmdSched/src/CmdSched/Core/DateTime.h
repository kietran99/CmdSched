#pragma once

#include "cspch.h"

namespace CmdSched::Core
{	
	struct DateTime
	{
		//enum WeekDays { MON, TUE, WED, THU, FRI, SAT, SUN};

		DateTime(int hour, int min, int day, int month, int year);
		DateTime(const DateTime& other);
		DateTime(DateTime&& other) noexcept;
		~DateTime();

		friend std::ostream& operator<<(std::ostream& os, const DateTime& time);

		int min, hour, day, month, year;
	};
}

