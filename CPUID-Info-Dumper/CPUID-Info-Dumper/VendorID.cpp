#include "stdafx.h"

#include "VendorID.h"

namespace CPUID_Info_Dumper
{
	// Class Constructors //////////////////////////////////////////////////////

	VendorID::VendorID()
	{
		for (int index = 0; index < 13; index++)
		{
			this->vendorID[index] = '\0';
		}
	}

	VendorID::VendorID(Register ebx, Register ecx, Register edx)
	{
		this->update(ebx, ecx, edx);
	}





	// Methods /////////////////////////////////////////////////////////////////
	
	void VendorID::update(Register ebx, Register ecx, Register edx)
	{
		this->vendorID[0] = ebx.getBits(0, 8);
		this->vendorID[1] = ebx.getBits(8, 8);
		this->vendorID[2] = ebx.getBits(16, 8);
		this->vendorID[3] = ebx.getBits(24, 8);
		this->vendorID[4] = edx.getBits(0, 8);
		this->vendorID[5] = edx.getBits(8, 8);
		this->vendorID[6] = edx.getBits(16, 8);
		this->vendorID[7] = edx.getBits(24, 8);
		this->vendorID[8] = ecx.getBits(0, 8);
		this->vendorID[9] = ecx.getBits(8, 8);
		this->vendorID[10] = ecx.getBits(16, 8);
		this->vendorID[11] = ecx.getBits(24, 8);
		this->vendorID[12] = '\0';
	}





	// Getters and Setters /////////////////////////////////////////////////////
	
	char* VendorID::getVendorIDString()
	{
		return this->vendorID;
	}
}