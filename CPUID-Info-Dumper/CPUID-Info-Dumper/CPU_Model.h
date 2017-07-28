#pragma once

#include "stdafx.h"

#include "Register.h"

namespace CPUID_Info_Dumper
{
	class CPU_Model
	{
		Register register1;

		int steppingID;
		int modelNumber;
		int familyCode;
		int type;
		int extendedModel;
		int extendedFamily;

		// Class Constructor
		CPU_Model(Register input); // CPUID(eax = 0x1) -> edx register

		// Setters and Getters
		int getSteppingID();
		int getModelNumber();
		int getFamilyCode();
		int getType();
		int getExtendedModel();
		int getExtendedFamily();
	};
}