#include "stdafx.h"

#include "FeatureFlags.h"

namespace CPUID_Info_Dumper
{
	// Class Constructors //////////////////////////////////////////////////////
	
	FeatureFlags::FeatureFlags()
	{
		this->featureFlagMap = std::map<CPU_Feature, bool>();
	}

	FeatureFlags::FeatureFlags(Register ecx, Register edx)
	{
		update(ecx, edx);
	}





	// Methods /////////////////////////////////////////////////////////////////
	
	void FeatureFlags::update(Register ecx, Register edx)
	{
		featureFlagMap[sse3] =		ecx.isBitSet(0);
		featureFlagMap[pclmuldq] =	ecx.isBitSet(1);
		featureFlagMap[dtes64] =	ecx.isBitSet(2);
		featureFlagMap[monitor] =	ecx.isBitSet(3);
		featureFlagMap[ds_cpl] =	ecx.isBitSet(4);
		featureFlagMap[vmx] =		ecx.isBitSet(5);
		featureFlagMap[smx] =		ecx.isBitSet(6);
		featureFlagMap[est] =		ecx.isBitSet(7);
		featureFlagMap[tm2] =		ecx.isBitSet(8);
		featureFlagMap[ssse3] =		ecx.isBitSet(9);
		featureFlagMap[cnxt_id] =	ecx.isBitSet(10);
		featureFlagMap[ecx_reserved11] = ecx.isBitSet(11);
		featureFlagMap[ecx_reserved12] = ecx.isBitSet(12);
		featureFlagMap[cx16] =		ecx.isBitSet(13);
		featureFlagMap[xtpr] =		ecx.isBitSet(14);
		featureFlagMap[pdcm] =		ecx.isBitSet(15);
		featureFlagMap[ecx_reserved16] = ecx.isBitSet(16);
		featureFlagMap[ecx_reserved17] = ecx.isBitSet(17);
		featureFlagMap[dca] =		ecx.isBitSet(18);
		featureFlagMap[sse4_1] =	ecx.isBitSet(19);
		featureFlagMap[sse4_2] =	ecx.isBitSet(20);
		featureFlagMap[x2apic] =	ecx.isBitSet(21);
		featureFlagMap[movbe] =		ecx.isBitSet(22);
		featureFlagMap[popcnt] =	ecx.isBitSet(23);
		featureFlagMap[ecx_reserved24] = ecx.isBitSet(24);
		featureFlagMap[aes] =		ecx.isBitSet(25);
		featureFlagMap[xsave] =		ecx.isBitSet(26);
		featureFlagMap[osxsave] =	ecx.isBitSet(27);
		featureFlagMap[ecx_reserved28] = ecx.isBitSet(28);
		featureFlagMap[ecx_reserved29] = ecx.isBitSet(29);
		featureFlagMap[ecx_reserved30] = ecx.isBitSet(30);
		featureFlagMap[ecx_reserved31] = ecx.isBitSet(31);

		featureFlagMap[fpu] =		edx.isBitSet(0);
		featureFlagMap[vme] =		edx.isBitSet(1);
		featureFlagMap[de] =		edx.isBitSet(2);
		featureFlagMap[pse] =		edx.isBitSet(3);
		featureFlagMap[tsc] =		edx.isBitSet(4);
		featureFlagMap[msr] =		edx.isBitSet(5);
		featureFlagMap[pae] =		edx.isBitSet(6);
		featureFlagMap[mce] =		edx.isBitSet(7);
		featureFlagMap[cx8] =		edx.isBitSet(8);
		featureFlagMap[apic] =		edx.isBitSet(9);
		featureFlagMap[edx_reserved10] = edx.isBitSet(10);
		featureFlagMap[sep] =		edx.isBitSet(11);
		featureFlagMap[mtrr] =		edx.isBitSet(12);
		featureFlagMap[pge] =		edx.isBitSet(13);
		featureFlagMap[mca] =		edx.isBitSet(14);
		featureFlagMap[cmov] =		edx.isBitSet(15);
		featureFlagMap[pat] =		edx.isBitSet(16);
		featureFlagMap[pse_36] =	edx.isBitSet(17);
		featureFlagMap[psn] =		edx.isBitSet(18);
		featureFlagMap[clfsh] =		edx.isBitSet(19);
		featureFlagMap[edx_reserved20] = edx.isBitSet(20);
		featureFlagMap[ds] =		edx.isBitSet(21);
		featureFlagMap[acpi] =		edx.isBitSet(22);
		featureFlagMap[mmx] =		edx.isBitSet(23);
		featureFlagMap[fxsr] =		edx.isBitSet(24);
		featureFlagMap[sse] =		edx.isBitSet(25);
		featureFlagMap[sse2] =		edx.isBitSet(26);
		featureFlagMap[ss] =		edx.isBitSet(27);
		featureFlagMap[htt] =		edx.isBitSet(28);
		featureFlagMap[tm] =		edx.isBitSet(29);
		featureFlagMap[edx_reserved30] = edx.isBitSet(30);
		featureFlagMap[pbe] =		edx.isBitSet(31);
	}





	// Getters and Setters /////////////////////////////////////////////////////
	
	std::map<FeatureFlags::CPU_Feature, bool> FeatureFlags::getFeatureFlagMap()
	{
		return this->featureFlagMap;
	}
}