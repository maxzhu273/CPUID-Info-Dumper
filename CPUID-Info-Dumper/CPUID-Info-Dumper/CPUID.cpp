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

		this->output0x2 = std::vector<CPUID_Output>();
		this->cacheDescriptorList = CacheDescriptorList();

		this->output0x3 = CPUID_Output();

		this->output0x4 = std::vector<CPUID_Output>();

		this->update();
	}





	// Methods /////////////////////////////////////////////////////////////////

	CPUID_Output CPUID::runCPUID(int eax, int ecx)
	{
		int result[4];
		__cpuidex(result, eax, ecx);

		return CPUID_Output(result);
	}



	void CPUID::update()
	{
		// EAX = 0x0
		this->output0x0 = runCPUID(0x0);
		this->largestStandardFunctionNumberSupported = this->output0x0.eax.getValue();
		this->vendorID.update(this->output0x0.ebx, this->output0x0.ecx, this->output0x0.edx);



		// EAX = 0x1
		this->output0x1 = runCPUID(0x1);
		this->cpuModel.update(this->output0x1.eax);
		this->featureFlags.update(this->output0x1.ecx, this->output0x1.edx);



		// EAX = 0x2
		this->output0x2 = this->cacheDescriptorList.update();



		// EAX = 0x3
		this->output0x3 = runCPUID(0x3);



		// EAX = 0x4
	}



	

	// Getters and Setters /////////////////////////////////////////////////////
	// EAX = 0x0
	CPUID_Output CPUID::getOutput0x0()
	{
		return this->output0x0;
	}

	int CPUID::getLargestStandardFunctionNumberSupported()
	{
		return this->largestStandardFunctionNumberSupported;
	}

	char* CPUID::getVendorID()
	{
		return this->vendorID.getVendorIDString();
	}



	// EAX = 0x1
	CPUID_Output CPUID::getOutput0x1()
	{
		return this->output0x1;
	}

	CPU_Model CPUID::getCpuModel()
	{
		return this->cpuModel;
	}

	std::map<FeatureFlags::CPU_Feature, bool> CPUID::getFeatureFlagMap()
	{
		return this->featureFlags.getFeatureFlagMap();
	}

	bool CPUID::isFeatureFlagPresent(FeatureFlags::CPU_Feature feature)
	{
		return this->featureFlags.getFeatureFlagMap()[feature];
	}



	// EAX = 0x2
	std::vector<CPUID_Output> CPUID::getOutput0x2()
	{
		return this->output0x2;
	}

	std::vector<int> CPUID::getCacheDescriptorsVector()
	{
		return this->cacheDescriptorList.getVector();
	}



	//EAX = 0x3
	CPUID_Output CPUID::getOutput0x3()
	{
		return this->output0x3;
	}



	// EAX = 0x4
	std::vector<CPUID_Output> CPUID::getOutput0x4()
	{
		return this->output0x4;
	}
}