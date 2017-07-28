#include "stdafx.h"

#include <intrin.h>

#include "CPUID.h"

namespace CPUID_Info_Dumper
{
	CPUID_Output CPUID::runCPUID(int eax, int ecx = 0)
	{
		int result[4];
		__cpuidex(result, eax, ecx);

		CPUID_Output cpuid_Output = CPUID_Output();
		cpuid_Output.eax = result[0];
		cpuid_Output.ebx = result[1];
		cpuid_Output.ecx = result[2];
		cpuid_Output.edx = result[3];

		return cpuid_Output;
	}
}