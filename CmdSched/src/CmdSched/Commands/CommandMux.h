#pragma once

#include "BaseSchedule.h"
#include "BaseCommand.h"
#include <unordered_map>

namespace CmdSched::Command
{
	class CommandMux
	{
	public:
		CommandMux(Core::BaseSchedule* const& schedule);		
		~CommandMux();
				
		void RequestCommand();

	private:
		void InitializeAllCommands();
		std::stringstream GetInput();
		BaseCommand*& ExtractCommand(std::stringstream& ss);
		std::vector<std::string> ExtractArgs(std::stringstream& ss);
		BaseCommand*& FindCommand(std::string&& cmd);

	private:
		Core::BaseSchedule* schedule;

		BaseCommand* noCommand;
		std::unordered_map<std::string, BaseCommand*> cmdDict;
	};
}

