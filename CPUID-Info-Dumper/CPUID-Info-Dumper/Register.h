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



		// Methods /////////////////////////////////////////////////////////////
		int getBits(int startPos, int numberOfBits);
		int isBitSet(int position);



		// Setters and Getters /////////////////////////////////////////////////
		public:
		int getValue();
	};
}