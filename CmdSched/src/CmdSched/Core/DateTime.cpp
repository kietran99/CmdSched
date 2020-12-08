#include "cspch.h"
#include "DateTime.h"

namespace CmdSched::Core
{	
	DateTime::DateTime(int hour, int min, int day, int month, int year)
		: hour(hour), min(min), day(day), month(month), year(year)
	{
		//std::cout << "Constucting Time...\n";
	}

	DateTime::DateTime(const DateTime& other)
		: hour(other.hour), min(other.min), day(other.day), month(other.month), year(other.year)
	{
		//printf("Copying Time...\n");
	}

	DateTime::DateTime(DateTime&& other) noexcept
		: hour(other.hour), min(other.min), day(other.day), month(other.month), year(other.year)
	{
		//printf("Moving Time...\n");
	}
	
	DateTime::~DateTime()
	{
		//std::cout << "Destroying Time...\n";
	}
	
	std::ostream& operator<<(std::ostream& os, const DateTime& time)
	{
		auto DateTimeFormat = [](const int& num) { return (num < 10 ? "0" : "") + std::to_string(num); };
		os << DateTimeFormat(time.day) << '-' << DateTimeFormat(time.month) << '-' << DateTimeFormat(time.year) << ' '
			<< DateTimeFormat(time.hour) << ":" << DateTimeFormat(time.min);
		return os;
	}	
}
