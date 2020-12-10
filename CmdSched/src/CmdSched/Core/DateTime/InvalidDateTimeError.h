#pragma once

namespace CmdSched::Core::DateTime
{
	struct InvalidDateTimeError 
	{
	public:
		InvalidDateTimeError()
		{
			std::cout << "Invalid Date Time\n";
		}
	};
}