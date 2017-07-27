#include "stdafx.h"

#include "Register.h"

namespace CPUID_Info_Dumper
{
	Register::Register(int value)
	{
		this->value = value;
	}

	int Register::getBits(int startPos, int numberOfBits)
	{
		int mask = 0xffffffff >> (32 - numberOfBits);
		return (this->value >> startPos) & mask;
	}

	int Register::isBitSet(int position)
	{
		return (this->value >> position) & 0x1;
	}

	int Register::getValue()
	{
		return this->value;
	}
}

