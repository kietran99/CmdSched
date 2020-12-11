#pragma once

#include "DateTime.h"

namespace CmdSched::Core::DateTime::Director
{	
	using MaybeDateTime = Functional::Type::Either<InvalidDateTimeError, DateTime* const>;
	MaybeDateTime Build(const std::vector<std::string>& args);
	MaybeDateTime BuildUsingHM(const std::vector<std::string>& args);
	MaybeDateTime BuildUsingHMD(const std::vector<std::string>& args);
	MaybeDateTime BuildUsingHMDM(const std::vector<std::string>& args);
	MaybeDateTime BuildUsingHMDMY(const std::vector<std::string>& args);
}

