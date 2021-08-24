#pragma once

#include "DateTime.h"
#include "InvalidDateTimeError.h"

namespace CmdSched::Core::DateTime::Builder
{
	Functional::Type::Either<InvalidDateTimeError, DateTime* const> Construct(int hour, int min);

	DateTime* const SetDay(DateTime* const dt, int day);

	DateTime* const SetMonth(DateTime* const dt, int month);

	DateTime* const SetYear(DateTime* const dt, int year);
}

