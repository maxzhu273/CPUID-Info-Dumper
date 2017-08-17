#include "stdafx.h"
#include "CPUID_Output.h"

CPUID_Info_Dumper::CPUID_Output::CPUID_Output()
{
	this->eax = Register(0);
	this->ebx = Register(0);
	this->ecx = Register(0);
	this->edx = Register(0);
}

CPUID_Info_Dumper::CPUID_Output::CPUID_Output(int* fourElementArray)
{
	this->eax = Register(fourElementArray[0]);
	this->ebx = Register(fourElementArray[1]);
	this->ecx = Register(fourElementArray[2]);
	this->edx = Register(fourElementArray[3]);
}
