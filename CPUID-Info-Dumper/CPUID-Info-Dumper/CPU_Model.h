#pragma once

#include "stdafx.h"

#include "Register.h"

namespace CPUID_Info_Dumper
{
	class CPU_Model
	{
		private:
		int processorSignature;
		int steppingID;
		int modelNumber;
		int familyCode;
		int type;
		int extendedModel;
		int extendedFamily;



		// Class Constructors //////////////////////////////////////////////////
		public:
		CPU_Model(); // Default Constructor
		CPU_Model(Register eax);



		// Methods /////////////////////////////////////////////////////////////
		private:
		int calculateProcessorSignature(int registerValue);
		
		public:
		void update(Register eax);



		// Getters and Setters /////////////////////////////////////////////////
		public:
		int getProcessorSigature();
		int getSteppingID();
		int getModelNumber();
		int getFamilyCode();
		int getType();
		int getExtendedModel();
		int getExtendedFamily();
	};
}