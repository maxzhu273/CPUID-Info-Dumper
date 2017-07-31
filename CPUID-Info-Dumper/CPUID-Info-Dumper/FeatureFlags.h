#pragma once

#include "stdafx.h"

#include <map>

#include "Register.h"

namespace CPUID_Info_Dumper
{
	class FeatureFlags
	{
		enum CPU_Feature
		{
			//ecx
			sse3 = 0,	//ECX Bit 0: Streaming SIMD Extensions 3
			pclmuldq,	//ECX Bit 1: PCLMULDQ instruction
			dtes64,		//ECX Bit 2: 64-Bit Debug Store
			monitor,	//ECX Bit 3: MONITOR and MWAIT instructions
			ds_cpl,		//ECX Bit 4: CPL Qualified Debug Store
			vmx,		//ECX Bit 5: virtual Machine Extensions
			smx,		//ECX Bit 6: Safe Mode Extensions
			est,		//ECX Bit 7: Enhanced Intel SpeedStep Technology
			tm2,		//ECX Bit 8: Thermal Monitor 2
			ssse3,		//ECX Bit 9: Supplemental Streaming SIMD Extensions 3
			cnxt_id,	//ECX Bit 10: L1 Context ID
			ecx_reserved11,
			ecx_reserved12,
			cx16,		//ECX Bit 13: CMPXCHG16B instruction
			xtpr,		//ECX Bit 14: xTPR Update Control
			pdcm,		//ECX Bit 15: Perfmon and Debug Capacity
			ecx_reserved16,
			ecx_reserved17,
			dca,		//ECX Bit 18: Direct Cache Access
			sse4_1,		//ECX Bit 19: Streaming SIMD Extensions 4.1
			sse4_2,		//ECX Bit 20: Streaming SIMD Extensions 4.2
			x2apic,		//ECX Bit 21: Extended xAPIC Support
			movbe,		//ECX Bit 22: MOVBE Instruction
			popcnt,		//ECX Bit 23: POPCNT Instruction
			ecx_reserved24,
			aes,		//ECX Bit 25: AES Instruction
			xsave,		//ECX Bit 26: XSAVE and XSTOR states
			osxsave,	//ECX Bit 27: OS_Enabled Extended State Management
			ecx_reserved28,
			ecx_reserved29,
			ecx_reserved30,
			ecx_reserved31,

			//edx
			fpu,		//EDX Bit 0: Floating Point Unit
			vme,		//EDX Bit 1: Virtual 8086 Mode Enhancements
			de,			//EDX Bit 2: Debugging Extensions
			pse,		//EDX Bit 3: Page Size Extension
			tsc,		//EDX Bit 4: Time Stamp Controller
			msr,		//EDX Bit 5: Model Specific Registers
			pae,		//EDX Bit 6: Physical Address Extension
			mce,		//EDX Bit 7: Machine Check Exception
			cx8,		//EDX Bit 8: CMPXCHG8B (compare and exchange) Instruction
			apic,		//EDX Bit 9: Advanced Programmable Interrupt Controller
			edx_reserved10,
			sep,		//EDX Bit 11: SYSENTER and SYSEXIT instructions
			mtrr,		//EDX Bit 12: Memory Type Range Registers
			pge,		//EDX Bit 13: PTE Global Bit
			mca,		//EDX Bit 14: Mechine Check Architecture
			cmov,		//EDX Bit 15: Conditional Move Instructions
			pat,		//EDX Bit 16: Page Attribute Table
			pse_36,		//EDX Bit 17: 36-bit Page Size Extension
			psn,		//EDX Bit 18: Processor Serial Number
			clfsh,		//EDX Bit 19: CLFLUSH Instruction
			edx_reserved20,
			ds,			//EDX Bit 21: Debug Store
			acpi,		//EDX Bit 22: Thermal Monitor and Software Controlled Clock Facilities
			mmx,		//EDX Bit 23: Intel MMX Technology
			fxsr,		//EDX Bit 24: FXSAVE and FXSTOR instructions
			sse,		//EDX Bit 25: Streaming SIMD Extensions
			sse2,		//EDX Bit 26: Streaming SIMD Extensions 2
			ss,			//EDX Bit 27: Self Snoop
			htt,		//EDX Bit 28: Hyper Threading Technology
			tm,			//EDX Bit 29: Thermal Monitor
			edx_reserved30,
			pbe			//EDX Bit 31: Pending Break Enable
		};

		private:
		Register ecx;
		Register edx;
		std::map<CPU_Feature, bool> featureFlagMap;



		// Class Constructor ///////////////////////////////////////////////////
		public:
		FeatureFlags(); // Default Constructor
		FeatureFlags(Register ecx, Register edx);

		

		// Methods /////////////////////////////////////////////////////////////
		public:
		void update(Register ecx, Register edx);



		// Setters and Getters /////////////////////////////////////////////////
		public:
		std::map<CPU_Feature, bool> getFeatureFlagMap();
		bool getFeatureFlagStatus(CPU_Feature featureFlag);
		Register getEcx();
		Register getEdx();
	};
}