#include "cspch.h"
#include "Time.h"

namespace CmdSched::Core
{	
	Time::Time(int hour, int min, int sec, int day, int month, int year)
		: hour(hour), min(min), sec(sec), day(day), month(month), year(year)
	{
		//std::cout << "Constucting Time...\n";
	}

	Time::Time(const Time& other)
		: hour(other.hour), min(other.min), sec(other.sec), day(other.day), month(other.month), year(other.year)
	{
		//printf("Copying Time...\n");
	}

	Time::Time(Time&& other) noexcept
		: hour(other.hour), min(other.min), sec(other.sec), day(other.day), month(other.month), year(other.year)
	{
		//printf("Moving Time...\n");
	}
	
	Time::~Time()
	{
		//std::cout << "Destroying Time...\n";
	}
	
	std::ostream& operator<<(std::ostream& os, const Time& time)
	{
		auto TimeFormat = [](const int& num) { return (num < 10 ? "0" : "") + std::to_string(num); };
		os << TimeFormat(time.day) << '-' << TimeFormat(time.month) << '-' << TimeFormat(time.year) << ' '
			<< TimeFormat(time.hour) << ":" << TimeFormat(time.min) << ":" << TimeFormat(time.sec);
		return os;
	}	
}
