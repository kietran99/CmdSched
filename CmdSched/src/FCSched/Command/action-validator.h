#pragma once

#include "cspch.h"

#include "command-executor.h"

namespace Command
{
	std::optional<
		std::function<bool(Core::Schedule&, const std::vector<std::string>)>>
		TryGetAction(const std::string& actionAsStr);
}