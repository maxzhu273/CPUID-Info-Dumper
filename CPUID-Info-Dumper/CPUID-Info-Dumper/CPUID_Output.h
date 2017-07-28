#pragma once

#include "stdafx.h"

#include "Register.h"

namespace CPUID_Info_Dumper
{
	struct CPUID_Output
	{
		public:
		Register eax;
		Register ebx;
		Register ecx;
		Register edx;

		// Struct Constructor
		CPUID_Output();
	};
}