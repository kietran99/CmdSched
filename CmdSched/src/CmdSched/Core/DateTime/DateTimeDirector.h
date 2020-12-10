#pragma once

#include "DateTime.h"
#include "IDateTimeBuilder.h"

namespace CmdSched::Core::DateTime
{
	class DateTimeDirector
	{
	public:
		DateTimeDirector(IDateTimeBuilder* const& builder);
		~DateTimeDirector();

		//DateTime Build(int hour, int min);

	private:
		IDateTimeBuilder* builder;
	};
}

