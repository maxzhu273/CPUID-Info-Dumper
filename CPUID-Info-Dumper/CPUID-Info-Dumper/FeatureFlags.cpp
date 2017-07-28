#include "stdafx.h"

#include "FeatureFlags.h"

namespace CPUID_Info_Dumper
{
	FeatureFlags::FeatureFlags(Register ecx, Register edx) : ecx(ecx), edx(edx)
	{
		this->ecx = ecx;
		this->edx = edx;

		featureFlagMap[sse3] =		this->ecx.isBitSet(0);
		featureFlagMap[pclmuldq] =	this->ecx.isBitSet(1);
		featureFlagMap[dtes64] =	this->ecx.isBitSet(2);
		featureFlagMap[monitor] =	this->ecx.isBitSet(3);
		featureFlagMap[ds_cpl] =	this->ecx.isBitSet(4);
		featureFlagMap[vmx] =		this->ecx.isBitSet(5);
		featureFlagMap[smx] =		this->ecx.isBitSet(6);
		featureFlagMap[est] =		this->ecx.isBitSet(7);
		featureFlagMap[tm2] =		this->ecx.isBitSet(8);
		featureFlagMap[ssse3] =		this->ecx.isBitSet(9);
		featureFlagMap[cnxt_id] =	this->ecx.isBitSet(10);
		featureFlagMap[ecx_reserved11] = this->ecx.isBitSet(11);
		featureFlagMap[ecx_reserved12] = this->ecx.isBitSet(12);
		featureFlagMap[cx16] =		this->ecx.isBitSet(13);
		featureFlagMap[xtpr] =		this->ecx.isBitSet(14);
		featureFlagMap[pdcm] =		this->ecx.isBitSet(15);
		featureFlagMap[ecx_reserved16] = this->ecx.isBitSet(16);
		featureFlagMap[ecx_reserved17] = this->ecx.isBitSet(17);
		featureFlagMap[dca] =		this->ecx.isBitSet(18);
		featureFlagMap[sse4_1] =	this->ecx.isBitSet(19);
		featureFlagMap[sse4_2] =	this->ecx.isBitSet(20);
		featureFlagMap[x2apic] =	this->ecx.isBitSet(21);
		featureFlagMap[movbe] =		this->ecx.isBitSet(22);
		featureFlagMap[popcnt] =	this->ecx.isBitSet(23);
		featureFlagMap[ecx_reserved24] = this->ecx.isBitSet(24);
		featureFlagMap[aes] =		this->ecx.isBitSet(25);
		featureFlagMap[xsave] =		this->ecx.isBitSet(26);
		featureFlagMap[osxsave] =	this->ecx.isBitSet(27);
		featureFlagMap[ecx_reserved28] = this->ecx.isBitSet(28);
		featureFlagMap[ecx_reserved29] = this->ecx.isBitSet(29);
		featureFlagMap[ecx_reserved30] = this->ecx.isBitSet(30);
		featureFlagMap[ecx_reserved31] = this->ecx.isBitSet(31);

		featureFlagMap[fpu] =		this->edx.isBitSet(0);
		featureFlagMap[vme] =		this->edx.isBitSet(1);
		featureFlagMap[de] =		this->edx.isBitSet(2);
		featureFlagMap[pse] =		this->edx.isBitSet(3);
		featureFlagMap[tsc] =		this->edx.isBitSet(4);
		featureFlagMap[msr] =		this->edx.isBitSet(5);
		featureFlagMap[pae] =		this->edx.isBitSet(6);
		featureFlagMap[mce] =		this->edx.isBitSet(7);
		featureFlagMap[cx8] =		this->edx.isBitSet(8);
		featureFlagMap[apic] =		this->edx.isBitSet(9);
		featureFlagMap[edx_reserved10] = this->edx.isBitSet(10);
		featureFlagMap[sep] =		this->edx.isBitSet(11);
		featureFlagMap[mtrr] =		this->edx.isBitSet(12);
		featureFlagMap[pge] =		this->edx.isBitSet(13);
		featureFlagMap[mca] =		this->edx.isBitSet(14);
		featureFlagMap[cmov] =		this->edx.isBitSet(15);
		featureFlagMap[pat] =		this->edx.isBitSet(16);
		featureFlagMap[pse_36] =	this->edx.isBitSet(17);
		featureFlagMap[psn] =		this->edx.isBitSet(18);
		featureFlagMap[clfsh] =		this->edx.isBitSet(19);
		featureFlagMap[edx_reserved20] = this->edx.isBitSet(20);
		featureFlagMap[ds] =		this->edx.isBitSet(21);
		featureFlagMap[acpi] =		this->edx.isBitSet(22);
		featureFlagMap[mmx] =		this->edx.isBitSet(23);
		featureFlagMap[fxsr] =		this->edx.isBitSet(24);
		featureFlagMap[sse] =		this->edx.isBitSet(25);
		featureFlagMap[sse2] =		this->edx.isBitSet(26);
		featureFlagMap[ss] =		this->edx.isBitSet(27);
		featureFlagMap[htt] =		this->edx.isBitSet(28);
		featureFlagMap[tm] =		this->edx.isBitSet(29);
		featureFlagMap[edx_reserved30] = this->edx.isBitSet(30);
		featureFlagMap[pbe] =		this->edx.isBitSet(31);
	}

	std::map<FeatureFlags::CPU_Feature, bool> FeatureFlags::getFeatureFlagMap()
	{
		return this->featureFlagMap;
	}

	bool FeatureFlags::getFeatureFlagStatus(CPU_Feature featureFlag)
	{
		return this->featureFlagMap[featureFlag];
	}

	Register FeatureFlags::getEcx()
	{
		return this->ecx;
	}

	Register FeatureFlags::getEdx()
	{
		return this->edx;
	}
}