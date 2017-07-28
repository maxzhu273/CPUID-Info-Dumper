#pragma once

#include "stdafx.h"

namespace CPUID_Info_Dumper
{
	class Register
	{
		private:
		int value;

		// Class Constructors
		public:
		Register(int value);

		// Methods
		/*
		Returns an integer with the bits from position startPos to startPos + numberOfBits.
		The least significant bit is bit 0, and the most significant bit is bit 31.
		For example, with getBits(13, 4), this function will return an integer with the bits in position 13, 14, 15, and 16 in position 0, 1, 2, and 3
		If this->value = 0b01110101 11111011 00110100 00110110, the output to this.getBits(13, 4) would be 0b00000000 00000000 00000000 00001001
		*/
		int getBits(int startPos, int numberOfBits);
		/*
		Returns an integer with the bits from position startPos to startPos + numberOfBits removed.
		The least significant bit is bit 0, and the most significant bit is bit 31.
		For example, with removeBits(13, 4), this function will return an integer with the bits in position 13, 14, 15, and 16 removed, and bits 17+ ... in position 13+
		If this->value = 0b01110101 11111011 00110100 00110110, the output to this.getBits(13, 4) would be 0b00000111 01011111 10110100 00110110
		*/
		int removeBits(int startPos, int numberOfBits);
		/*
		Returns a single bit of this->value.  This is identical to calling getBits(pos, 1)
		*/
		int isBitSet(int pos);

		// Setters and Getters
		public:
		int getValue();
	};
}