#include "cspch.h"
#include "DateTimeDirector.h"

namespace CmdSched::Core::DateTime
{
    DateTimeDirector::DateTimeDirector(IDateTimeBuilder* const& builder)
        : builder(builder) {}

    DateTimeDirector::~DateTimeDirector()
    {
        delete builder;
    }

    /*DateTime DateTimeDirector::Build(int hour, int min)
    {
        builder->Construct(hour, min);
        
    }*/
}