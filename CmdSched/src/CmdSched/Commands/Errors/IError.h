#pragma once

#include "cspch.h"

namespace CmdSched::Command::Error
{
	class IError
	{
	public:
		virtual std::string GetMessage() = 0;
	};
}