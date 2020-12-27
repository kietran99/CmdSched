#pragma once

#include "IError.h"

namespace CmdSched::Command::Error
{
	class InvalidTaskName : public IError
	{
	public:
		virtual std::string GetMessage() override;
	};
}

