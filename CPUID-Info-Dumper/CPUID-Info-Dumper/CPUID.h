#pragma once

#include "stdafx.h"

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
		CPUID_Output output0x2;

		// EAX = 0x3
		CPUID_Output output0x3;


		// Class Constructor
		public:
		CPUID();



		// Methods
		private:
		CPUID_Output runCPUID(int eax, int ecx = 0);

		public:
		void update(); // Updates all fields

		// EAX = 0x0
		public:
		void parseVendorID(Register ebx, Register ecx, Register edx);

		// EAX = 0x1
		public:



		// Getters and Setters
		public:

		// EAX = 0x0
		int getLargestStandardFunctionNumberSupported();
		char* getVendorID();

		// EAX = 0x1
		CPU_Model getCpuModel();
		FeatureFlags getFeatureFlags();
	};
}