#include "cspch.h"
#include "InvalidTaskName.h"

namespace CmdSched::Command::Error
{
	std::string InvalidTaskName::GetMessage()
	{
		return "Error: Invalid Task Name";
	}
}