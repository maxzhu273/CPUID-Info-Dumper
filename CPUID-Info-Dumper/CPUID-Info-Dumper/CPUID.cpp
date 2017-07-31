#include "stdafx.h"

#include <intrin.h>

#include "CPUID.h"

namespace CPUID_Info_Dumper
{
	// Class Constructor ///////////////////////////////////////////////////////

	CPUID::CPUID()
	{
		this->output0x0 = CPUID_Output();
		this->vendorID = VendorID();

		this->output0x1 = CPUID_Output();
		this->cpuModel = CPU_Model();
		this->featureFlags = FeatureFlags();

		this->output0x2 = CPUID_Output();

		this->output0x3 = CPUID_Output();
	}





	// Methods /////////////////////////////////////////////////////////////////

	CPUID_Output CPUID::runCPUID(int eax, int ecx)
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

	void CPUID::update()
	{
		// EAX = 0x0
		output0x0 = runCPUID(0x0);
		this->largestStandardFunctionNumberSupported = output0x0.eax.getValue();
		this->vendorID.update(output0x0.ebx, output0x0.ecx, output0x0.edx);

		// EAX = 0x1
		output0x1 = runCPUID(0x1);
		this->cpuModel.update(output0x1.eax);
		this->featureFlags.update(output0x1.ecx, output0x1.edx);
	}



	

	// Getters and Setters /////////////////////////////////////////////////////

	int CPUID::getLargestStandardFunctionNumberSupported()
	{
		return this->largestStandardFunctionNumberSupported;
	}

	char* CPUID::getVendorID()
	{
		return this->vendorID.getVendorIDString();
	}

	CPU_Model CPUID::getCpuModel()
	{
		return this->cpuModel;
	}

	FeatureFlags CPUID::getFeatureFlags()
	{
		return this->featureFlags;
	}
}