#include "stdafx.h"
#include "CPU_Model.h"

namespace CPUID_Info_Dumper
{
	// Class Constructors //////////////////////////////////////////////////////
	
	CPU_Model::CPU_Model()
	{
		this->processorSignature = 0;
		this->steppingID = 0;
		this->modelNumber = 0;
		this->familyCode = 0;
		this->type = 0;
		this->extendedModel = 0;
		this->extendedFamily = 0;
	}

	CPU_Model::CPU_Model(Register eax)
	{
		update(eax);
	}




	
	// Methods /////////////////////////////////////////////////////////////////
	
	int CPU_Model::calculateProcessorSignature(int registerValue)
	{
		return Register(registerValue).removeBits(28, 4).removeBits(14, 2).getValue();
	}
	
	void CPU_Model::update(Register eax)
	{
		this->processorSignature = calculateProcessorSignature(eax.getValue());
		this->steppingID = eax.getBits(0, 4);
		this->modelNumber = eax.getBits(4, 4);
		this->familyCode = eax.getBits(8, 4);
		this->type = eax.getBits(12, 2);
		this->extendedModel = eax.getBits(16, 4);
		this->extendedFamily = eax.getBits(20, 8);
	}





	// Getters and Setters /////////////////////////////////////////////////////
	
	int CPU_Model::getProcessorSigature()
	{
		return this->processorSignature;
	}

	int CPU_Model::getSteppingID()
	{
		return this->steppingID;
	}

	int CPU_Model::getModelNumber()
	{
		return this->modelNumber;
	}

	int CPU_Model::getFamilyCode()
	{
		return this->familyCode;
	}

	int CPU_Model::getType()
	{
		return this->type;
	}

	int CPU_Model::getExtendedModel()
	{
		return this->extendedModel;
	}

	int CPU_Model::getExtendedFamily()
	{
		return this->extendedFamily;
	}
}
