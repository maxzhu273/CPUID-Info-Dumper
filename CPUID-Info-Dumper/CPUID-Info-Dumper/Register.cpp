#include "stdafx.h"

#include "Register.h"

namespace CPUID_Info_Dumper
{
	// Class Constructors //////////////////////////////////////////////////////
	
	Register::Register()
	{
		this->value = 0;
	}

	Register::Register(int value)
	{
		this->value = value;
	}




	
	// Methods /////////////////////////////////////////////////////////////////
	
	Register& Register::removeBits(int startPos, int numberOfBits)
	{
		int lowerHalf = this->value & (0xffffffff >> (32 - startPos));
		int upperHalf = (this->value >> numberOfBits) & (0xffffffff << startPos);

		this->value = upperHalf | lowerHalf;
		return *this;
	}

	int Register::removeBitsReadOnly(int startPos, int numberOfBits)
	{
		int lowerHalf = this->value & (0xffffffff >> (32 - startPos));
		int upperHalf = (this->value >> numberOfBits) & (0xffffffff << startPos);

		return upperHalf | lowerHalf;
	}

	int Register::isBitSet(int pos)
	{
		return (this->value >> pos) & 0x1;
	}





	// Getters and Setters /////////////////////////////////////////////////////
	
	int Register::getValue()
	{
		return this->value;
	}

	void Register::setValue(int value)
	{
		this->value = value;
	}

	
	int Register::getBits(int startPos, int numberOfBits)
	{
		int mask = 0xffffffff >> (32 - numberOfBits);
		return (this->value >> startPos) & mask;
	}
}

