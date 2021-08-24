#include "cspch.h"

#include "logger.h"

void LogSuccess(const char* msg)
{
	printf("\033[0;32m");
	printf("SUCCESS: %s\n", msg);
	printf("\033[0;37m");
}

void LogWarning(const char* msg)
{
	printf("\033[0;33m");
	printf("WARNING: %s\n", msg);
	printf("\033[0;37m");
}

void LogError(const char* msg)
{
	printf("\033[0;31m");
	printf("ERROR: %s\n", msg);
	printf("\033[0;37m");
}