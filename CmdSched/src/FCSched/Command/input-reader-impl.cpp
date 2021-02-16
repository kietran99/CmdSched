#include "cspch.h"

#include "input-reader.h"

#include <sstream>
#include <algorithm>
#include <tuple>
#include <variant>

namespace Command
{
	//-----------------------Internal Declarations------------------------------
	ArgList ExtractArgsFromInput(std::istream& input);
	ArgList PopulateArgList(ArgList argList, std::stringstream& ss, const int remainingArgCnt);
	const std::variant<InvalidCommandError, CommandData> ResolveInput(const ArgList& args);
	std::optional
		<std::tuple
		<std::function<bool(Core::Schedule&, const std::vector<std::string>)>, int>>
		TryExtractValidAction(const ArgList& args);
	std::optional
		<std::tuple
		<std::function<bool(Core::Schedule&, const std::vector<std::string>)>, int>>
		TryExtractSingleArgValidAction(const std::string& arg);
	//-----------------------------------------------------------------



	const std::variant<InvalidCommandError, CommandData> ReadInput(std::istream& input)
	{
		return ResolveInput(ExtractArgsFromInput(input));
	}

	const std::variant<InvalidCommandError, CommandData> ResolveInput(const ArgList& args)
	{
		auto maybeExecutorAndIdx = TryExtractValidAction(args);

		if (!maybeExecutorAndIdx.has_value())
		{
			return InvalidCommandError();
		}

		auto&[executor, valuesStartIdx] = *maybeExecutorAndIdx;
		auto valueListSize = args.size() - valuesStartIdx;
		
		if (valueListSize == 0)
		{
			return CommandData(executor, {});
		}

		std::vector<std::string> values(valueListSize);
		std::copy(args.begin() + valuesStartIdx, args.end(), values.begin());
		return CommandData(executor, values);
	}

	std::optional
		<std::tuple
		<std::function<bool(Core::Schedule&, const std::vector<std::string>)>, int>> 
		TryExtractValidAction(const ArgList& args)
	{
		if (args.size() == 0)
		{
			return std::make_tuple(Command::Refresh, 0);
		}

		if (args.size() == 1)
		{
			return TryExtractSingleArgValidAction(args[0]);
		}

		std::string tryMatchActionStr = "";

		for (int i = 0; i < args.size(); i++)
		{
			tryMatchActionStr.append(args[i]);
			
			auto executor = TryGetAction(tryMatchActionStr);

			if (executor)
			{
				return std::make_tuple(*executor, i + 1);
			}

			tryMatchActionStr.append((i < args.size() - 1 ? " " : ""));
		}

		return std::nullopt;
	}

	std::optional
		<std::tuple
		<std::function<bool(Core::Schedule&, const std::vector<std::string>)>, int>> 
		TryExtractSingleArgValidAction(const std::string& arg)
	{
		auto executor = TryGetAction(arg);

		if (executor)
		{
			return std::make_tuple(*executor, 1);
		}

		return std::nullopt;
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