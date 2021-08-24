#include "cspch.h"
#include "DateTimeDirector.h"
#include "DefaultDateTimeBuilder.h"
#include <chrono>
#include <unordered_map>

namespace CmdSched::Core::DateTime::Director
{	
	tm GetCurrentDateTime();
	int GetCurrentDay();
	int GetCurrentMonth();
	int GetCurrentYear();
	bool IsDayValid(int day);
	bool IsMonthValid(int month);
	bool IsYearValid(int year);
	std::vector<std::string> GetAppendedArgs(const std::vector<std::string>& dtArgs, const std::string& extra);

	MaybeDateTime Build(const std::vector<std::string>& dtArgs)
	{
		std::unordered_map<size_t, MaybeDateTime (*)(const std::vector<std::string>&)> constructorMap =
		{
			{ 2, BuildUsingHM }, { 3, BuildUsingHMD }, { 4, BuildUsingHMDM }, { 5, BuildUsingHMDMY }
		};

		return constructorMap[dtArgs.size()](dtArgs);
	}	

	MaybeDateTime BuildUsingHM(const std::vector<std::string>& dtArgs)
	{				
		return BuildUsingHMD(GetAppendedArgs(dtArgs, std::to_string(GetCurrentDay())));
	}

	MaybeDateTime BuildUsingHMD(const std::vector<std::string>& dtArgs)
	{
		return BuildUsingHMDM(GetAppendedArgs(dtArgs, std::to_string(GetCurrentMonth())));
	}

	MaybeDateTime BuildUsingHMDM(const std::vector<std::string>& dtArgs)
	{
		return BuildUsingHMDMY(GetAppendedArgs(dtArgs, std::to_string(GetCurrentYear())));
	}

	MaybeDateTime BuildUsingHMDMY(const std::vector<std::string>& dtArgs)
	{
		return Builder::Construct(stoi(dtArgs[0]), stoi(dtArgs[1]))
			.Map(Builder::SetDay, IsDayValid, stoi(dtArgs[2]))
			.Map(Builder::SetMonth, IsMonthValid, stoi(dtArgs[3]))
			.Map(Builder::SetYear, IsYearValid, stoi(dtArgs[4]));
	}

	tm GetCurrentDateTime()
	{
		time_t curTimeT;
		tm curDateTime;

		_time64(&curTimeT);
		_localtime64_s(&curDateTime, &curTimeT);
		return curDateTime;
	}

	int GetCurrentDay()
	{
		return GetCurrentDateTime().tm_mday;
	}

	int GetCurrentMonth()
	{
		return GetCurrentDateTime().tm_mon + 1;
	}

	int GetCurrentYear()
	{
		return GetCurrentDateTime().tm_year + 1900;
	}

	bool IsDayValid(int day)
	{
		return day > 0 && day < 32;
	}

	bool IsMonthValid(int month)
	{
		return month > 0 && month < 13;
	}

	bool IsYearValid(int year)
	{
		return year >= GetCurrentYear();
	}

	std::vector<std::string> GetAppendedArgs(const std::vector<std::string>& dtArgs, const std::string& extra)
	{
		std::vector<std::string> extraArgs = dtArgs;
		extraArgs.push_back(extra);
		return extraArgs;
	}
}