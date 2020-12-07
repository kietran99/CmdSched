#include "cspch.h"
#include "CommandMux.h"
#include "NoCommand.h"
#include "AddTaskCommand.h"
#include <sstream>

namespace CmdSched::Commands
{
	CommandMux::CommandMux(Core::BaseSchedule* const& schedule)
		: schedule(schedule)
	{
		printf("Constructing Command Mux\n");

		cmdDict = 
		{
			{"add task", new AddTaskCommand()}
		};
		
		std::cout << "Available Commands: " << std::endl;
		for (auto& kv : cmdDict)
		{
			std::cout << kv.first << std::endl;
		}

		std::cout << std::endl;
	}

	CommandMux::~CommandMux()
	{
		//printf("Destroying Command Mux\n");
		for (auto& kv : cmdDict)
		{
			delete kv.second;
		}
	}

	void CommandMux::RequestCommand()
	{
		std::cout << "Input command: ";				
		std::stringstream input = GetInput();
		BaseCommand*& cmd = ExtractCommand(input);
		std::vector<std::string> args = ExtractArgs(input);

		if (args.size() != cmd->GetArgsCount())
		{
			printf("The number of arguments does not match\n");
			return;
		}

		cmd->Execute(schedule, args);
	}

	std::stringstream CommandMux::GetInput()
	{
		std::string input;
		std::getline(std::cin, input);
		return std::stringstream(input);
		//return std::stringstream();
	}

	BaseCommand*& CommandMux::ExtractCommand(std::stringstream& ss)
	{
		std::string cmdName;

		for (std::string inter; ss >> inter;)
		{
			cmdName += inter;
			//std::cout << "Input Command: " << cmd << std::endl;

			BaseCommand*& cmd = FindCommand(std::move(cmdName));
			if (cmd != noCommand)
			{
				return cmd;
			}

			cmdName += " ";
		}
		
		std::cout << "Command " << cmdName << " does not exist\n";
		return noCommand;
	}	

	BaseCommand*& CommandMux::FindCommand(std::string&& cmd)
	{
		if (cmdDict.find(cmd) == cmdDict.end())
		{			
			return noCommand;
		}
		
		//std::cout << "Found Command!\n";
		return cmdDict[cmd];		
	}

	std::vector<std::string> CommandMux::ExtractArgs(std::stringstream& ss)
	{
		std::vector<std::string> args;

		//std::cout << "Args: " << std::endl;
		for (std::string arg; ss >> arg;)
		{
			//std::cout << arg << std::endl;
			args.push_back(arg);
		}

		return args;
	}

	/*void CommandMux::ExecuteCommand(const std::vector<std::string>& args)
	{
		std::cout << "Executing Command...\n";	
	}*/
}
