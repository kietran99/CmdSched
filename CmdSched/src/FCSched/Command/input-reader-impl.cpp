#include "cspch.h"

#include "input-reader.h"

#include <sstream>
#include <algorithm>

namespace Command
{
	//-----------------------Internal Declarations------------------------------
	ArgList ExtractArgsFromInput(std::istream& input);
	ArgList PopulateArgList(ArgList argList, std::stringstream& ss, const int remainingArgCnt);
	const Either<InvalidCommandError, CommandData> ResolveInput(const ArgList& args);
	//-----------------------------------------------------------------



	const Either<InvalidCommandError, CommandData> ReadInput(std::istream& input)
	{
		return ResolveInput(ExtractArgsFromInput(input));
	}

	const Either<InvalidCommandError, CommandData> ResolveInput(const ArgList& args)
	{
		std::string action = args[0];

		if (!IsValidAction(action))
		{
			return Either<InvalidCommandError, CommandData>(InvalidCommandError());
		}

		std::vector<std::string> values(args.size() - 1);
		std::copy(args.begin() + 1, args.end(), values.begin());
		return Either<InvalidCommandError, CommandData>(CommandData(action, values));
	}

	ArgList ExtractArgsFromInput(std::istream& input)
	{
		std::string str;
		std::getline(input, str);
		std::stringstream ss{ str };
		auto res = PopulateArgList({}, ss, MAX_ARGS);
		return res;
	}

	ArgList PopulateArgList(ArgList argList, std::stringstream& ss, const int remainingArgCnt)
	{
		if (remainingArgCnt == 0)
		{
			return argList;
		}

		if (std::string str; ss >> str)
		{
			argList.emplace_back(str);
			return PopulateArgList(argList, ss, remainingArgCnt - 1);
		}

		return argList;
	}	

	void LogInputArgs(const ArgList& args)
	{
		for (auto& v : args)
		{
			std::cout << v << std::endl;
		}
	}
}