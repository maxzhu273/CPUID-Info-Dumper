#include "stdafx.h"
#include "CPU_Model.h"

namespace CPUID_Info_Dumper
{
	CPU_Model::CPU_Model(Register input) : register1(input)
	{
		this->steppingID =		this->register1.getBits(0, 4);
		this->modelNumber =		this->register1.getBits(4, 4);
		this->familyCode =		this->register1.getBits(8, 4);
		this->type =			this->register1.getBits(12, 2);
		this->extendedModel =	this->register1.getBits(16, 4);
		this->extendedFamily =	this->register1.getBits(20, 8);
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
