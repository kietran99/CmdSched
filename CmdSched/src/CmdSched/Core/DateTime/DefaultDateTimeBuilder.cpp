#include "cspch.h"
#include "DefaultDateTimeBuilder.h"

namespace CmdSched::Core::DateTime::Builder
{
	Either<InvalidDateTimeError, DateTime* const> Construct(int hour, int min)
	{
		return DateTime::TryConstruct(hour, min);
	}

	DateTime* const SetDay(DateTime* const dt, int day)
	{
		dt->day = day;
		return dt;
	}

	DateTime* const SetMonth(DateTime* const dt, int month)
	{
		dt->month = month;
		return dt;
	}

	DateTime* const SetYear(DateTime* const dt, int year)
	{
		dt->year = year;
		return dt;
	}
}