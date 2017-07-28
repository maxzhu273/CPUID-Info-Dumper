#pragma once

#include "stdafx.h"

#include "CPUID_Output.h"

namespace CPUID_Info_Dumper
{
	class CPUID
	{
		// EAX = 0x0
		// Class Constructor
		CPUID()
		{

		}

		// Methods
		CPUID_Output runCPUID(int eax, int ecx = 0);


		// Getters and Setters
	};
}