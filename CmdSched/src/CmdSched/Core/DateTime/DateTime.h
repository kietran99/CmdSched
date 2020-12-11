#pragma once

#include "cspch.h"
#include "InvalidDateTimeError.h"

namespace CmdSched::Core::DateTime
{	
	class DateTime
	{
		//enum WeekDays { MON, TUE, WED, THU, FRI, SAT, SUN};
	private:
		DateTime(int hour, int min, int day = 1, int month = 1, int year = 2020);		

	public:
		// For testing purpose only
		//DateTime(Application int hour, int min, int day = 1, int month = 1, int year = 2020)
		DateTime(const DateTime& other);
		DateTime(DateTime&& other) noexcept;
		~DateTime();

		DateTime& operator=(DateTime&& other) noexcept
		{
			if (this != &other)
			{
				hour = other.hour;
				min = other.min;
				day = other.day;
				month = other.month;
				year = other.year;
			}

			return *this;
		}

		static Either<InvalidDateTimeError, DateTime* const> TryConstruct(int hour, int min);		

		
		friend std::ostream& operator<<(std::ostream& os, const DateTime& time);

	public:
		int hour, min, day, month, year;
	};
}

