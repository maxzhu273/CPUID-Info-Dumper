// CPUID-Info-Dumper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iomanip>
#include <iostream>

#include "CPUID.h"
#include "Register.h"


int main()
{
	using namespace std;
	using namespace CPUID_Info_Dumper;

	CPUID cpuid = CPUID();
	cpuid.update();

	cout << hex // show numbers in hex
		<< showbase // show the 0x prefix
		<< internal // fill between the prefix and the number
		<< setfill('0'); // fill with 0s
	cout << "EAX = 0x0" << endl;
	cout << "Largest Std Function: " << setw(10) << cpuid.getLargestStandardFunctionNumberSupported() << endl;
	cout << "VendorID: " << cpuid.getVendorID() << endl;
	cout << endl;
	cout << "EAX = 0x1" << endl;
	cout << "Processor Signature: " << setw(7) << cpuid.getCpuModel().getProcessorSigature() << endl;
	cout << "Feature Flags: ecx = " << setw(10) << cpuid.getFeatureFlags().getEcx().getValue() << " edx = " << setw(10) << cpuid.getFeatureFlags().getEdx().getValue() << endl;

    return 0;
}

