// CPUID-Info-Dumper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iomanip> // std::internal, std::showbase, std::setfill
#include <iostream> // std::cout
//#include <vector> // std::vector::iterator

#include "CPUID.h"
#include "Register.h"


int main()
{
	using namespace std;
	using namespace CPUID_Info_Dumper;

	CPUID cpuid = CPUID();

	cout << hex // show numbers in hex
		<< showbase // show the 0x prefix
		<< internal // fill between the prefix and the number
		<< setfill('0'); // fill with 0s
	cout << "EAX = 0x0 -- Largest Standard Function, VendorID" << endl;
	cout << "Largest Std Function: " << setw(10) << cpuid.getLargestStandardFunctionNumberSupported() << endl;
	cout << "VendorID: " << cpuid.getVendorID() << endl;
	cout << endl;
	cout << "EAX = 0x1 -- Processor Signature, Misc Info, Feature Flags" << endl;
	cout << "Processor Signature: " << setw(7) << cpuid.getCpuModel().getProcessorSigature() << endl;
	cout << "TODO: Misc Info" << endl;
	cout << "Feature Flags: ecx = " << setw(10) << cpuid.getOutput0x1().ecx.getValue() << " edx = " << setw(10) << cpuid.getOutput0x1().edx.getValue() << endl;
	cout << endl;
	cout << "EAX = 0x2 -- Cache Descriptors" << endl;
	cout << "Cache Descriptors:";
	for (int index = 0; index < cpuid.getCacheDescriptorsVector().size(); index++)
	{
		cout << " " << setw(4) << cpuid.getCacheDescriptorsVector()[index];
	}
	cout << endl << endl;
	cout << "EAX = 0x3 -- Processor Serial Number" << endl;
	cout << "Processor Signature only supported on Pentium III CPUs" << endl;
	cout << endl;
	cout << "EAX = 0x4 -- Deterministic Cache Parameters" << endl;


    return 0;
}

