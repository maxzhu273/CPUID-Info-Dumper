#pragma once

#include "stdafx.h"

#include "Register.h"

namespace CPUID_Info_Dumper
{
	class VendorID
	{
		char vendorID[13];

		

		// Class Constructors //////////////////////////////////////////////////
		public:
		VendorID();
		VendorID(Register ebx, Register ecx, Register edx);




		// Methods /////////////////////////////////////////////////////////////
		public:
		void update(Register ebx, Register ecx, Register edx);



		// Getters and Setters /////////////////////////////////////////////////
		public:
		char* getVendorIDString();
	};
}