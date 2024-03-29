#include "cspch.h"

#include "command-executor.h"

namespace Command
{
	//-------------------INTERNAL DECLARTIONS-----------------------------
	bool MatchNumberArgs(ArgValues values, int nArgs);
	bool MatchNumberArgsWithNaming(ArgValues values, int nArgs);
	std::string MakeNameFromArgVals(ArgValues values, int toEndIdx);
	std::optional<const unsigned short> StrToUShort(const std::string& s);
	bool IsValidMonth(u_short month);
	bool IsValidYear(u_short year);
	bool IsValidDay(u_short day, u_short month, u_short year);
	bool IsInValidRange(u_short val, u_short min, u_short max);
	//--------------------------------------------------------------------


	bool Execute(
		std::function<bool(Core::Schedule& schedule, std::vector<std::string>)> fn, 
		Core::Schedule& schedule, 
		ArgValues values)
	{
		return fn(schedule, values);
	}

	bool Show(Core::Schedule& schedule, ArgValues values)
	{
		if (!MatchNumberArgs(values, 0))
		{
			return false;
		}

		schedule.Show();
		return true;
	}

	bool Exit(Core::Schedule& schedule, ArgValues values)
	{
		exit(0);
		return true;
	}

	bool Refresh(Core::Schedule& schedule, ArgValues values)
	{
		return true;
	}

	bool Add(Core::Schedule& schedule, ArgValues values)
	{
		if (!MatchNumberArgsWithNaming(values, 4))
		{
			return false;
		}

		auto maybeDay = StrToUShort(values[values.size() - 3]), 
			maybeMonth = StrToUShort(values[values.size() - 2]),
			maybeYear = StrToUShort(values[values.size() - 1]);

		if (!maybeDay || !maybeMonth || !maybeYear)
		{
			LogError("Arguments must be positive whole numbers");
			return false;
		}

		auto day = *maybeDay, month = *maybeMonth, year = *maybeYear;

		if (!IsValidMonth(month))
		{
			LogError("Invalid Month");
			return false;
		}

		if (!IsValidYear(year))
		{
			LogError("Invalid Year");
			return false;
		}

		if (!IsValidDay(day, month, year))
		{
			LogError("Invalid Day");
			return false;
		}

		schedule.AddTask({ MakeNameFromArgVals(values, 3), day, month, year });
		LogSuccess("Added Task");
		return true;
	}

	std::optional<const unsigned short> StrToUShort(const std::string& s)
	{
		auto IsNumber = [](const std::string& s)
		{ 
			return 
				!s.empty() &&
				std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
		};
		
		if (IsNumber(s))
		{
			return static_cast<const unsigned short>(stoul(s));
		}
		else
		{
			return std::nullopt;
		}
	}
	
	bool IsValidDay(u_short day, u_short month, u_short year) 
	{ 
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			return IsInValidRange(day, 1, 31);
		}

		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			return IsInValidRange(day, 1, 30);
		}
			
		auto IsLeapYear = [](u_short year) { 
			return (year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
		};

		return IsInValidRange(day, 1, (IsLeapYear(year) ? 29 : 28));
	}

	bool IsValidMonth(u_short month) { return IsInValidRange(month, 1, 12); }
	
	bool IsValidYear(u_short year) { return IsInValidRange(year, 2021, 3000); }
	
	bool IsInValidRange(u_short val, u_short min, u_short max) { return val <= max && val >= min; }

	bool RemoveName(Core::Schedule& schedule, ArgValues values)
	{
		if (!MatchNumberArgsWithNaming(values, 1))
		{
			return false;
		}

		if (!schedule.RemoveName(MakeNameFromArgVals(values, 0)))
		{
			LogWarning("No Task with corresponding name was found");
			return false;
		}

		LogSuccess("Removed Task");
		return true;
	}

	bool RemoveAt(Core::Schedule& schedule, ArgValues values)
	{
		if (!MatchNumberArgs(values, 1))
		{
			return false;
		}

		auto maybeRemovePos = StrToUShort(values[0]);

		if (!maybeRemovePos)
		{
			LogError("Arguments must be positive whole numbers");
			return false;
		}

		if (!schedule.RemoveAt(*maybeRemovePos))
		{
			LogError("Index out of Range");
			return false;
		}

		LogSuccess("Removed Task");
		return true;
	}

	bool MatchNumberArgs(ArgValues values, int nArgs)
	{
		if (values.size() != nArgs)
		{
			LogError("Number of Arguments does not match!");
			return false;
		}

		return true;
	}
	
	bool MatchNumberArgsWithNaming(ArgValues values, int nArgs)
	{
		if (values.size() < nArgs)
		{
			LogError("Number of Arguments does not match!");
			return false;
		}

		return true;
	}

	std::string MakeNameFromArgVals(ArgValues values, int toEndIdx)
	{
		std::string name = "";

		for (size_t i = 0, lastIdx = values.size() - toEndIdx; i < lastIdx; i++)
		{
			name.append(values[i] + (i != lastIdx ? " " : ""));
		}

		return name;
	}
}