#pragma once

#include "stdafx.h"

#include <map> // std::map
#include <vector> // std::vector

#include "CacheDescriptorList.h"
#include "CPUID_Output.h"
#include "CPU_Model.h"
#include "FeatureFlags.h"
#include "VendorID.h"

namespace CPUID_Info_Dumper
{
	class CPUID
	{
		private:
		// EAX = 0x0
		CPUID_Output output0x0;
		int largestStandardFunctionNumberSupported;
		VendorID vendorID;

		// EAX = 0x1
		CPUID_Output output0x1;
		CPU_Model cpuModel;
		FeatureFlags featureFlags;

		// EAX = 0x2
		std::vector<CPUID_Output> output0x2;
		CacheDescriptorList cacheDescriptorList;

		// EAX = 0x3
		CPUID_Output output0x3;

		// EAX = 0x4;
		std::vector<CPUID_Output> output0x4;


		// Class Constructor ///////////////////////////////////////////////////
		public:
		CPUID();



		// Methods /////////////////////////////////////////////////////////////
		public:
		static CPUID_Output runCPUID(int eax, int ecx = 0);
		void update(); // Updates all fields



		// Getters and Setters /////////////////////////////////////////////////
		public:

		// EAX = 0x0
		CPUID_Output getOutput0x0();
		int getLargestStandardFunctionNumberSupported();
		char* getVendorID();

		// EAX = 0x1
		CPUID_Output getOutput0x1();
		CPU_Model getCpuModel();
		std::map<FeatureFlags::CPU_Feature, bool> getFeatureFlagMap();
		bool CPUID::isFeatureFlagPresent(FeatureFlags::CPU_Feature feature);

		// EAX = 0x2
		std::vector<CPUID_Output> getOutput0x2();
		std::vector<int> getCacheDescriptorsVector();

		// EAX = 0x3
		CPUID_Output getOutput0x3();

		// EAX = 0x4
		std::vector<CPUID_Output> getOutput0x4();

	};
}