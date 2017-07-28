// CPUID-Info-Dumper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <bitset>
#include <iostream>

#include "Register.h"


int main()
{
	using namespace std;
	using namespace CPUID_Info_Dumper;

	Register test = Register(0b01110101111110110011010000110110);
	cout << "test = " << test.getValue() << endl;
	cout << "removeBits(13, 4) = " << test.removeBits(13, 4) << endl;
	cout << "getBits(13, 4) = " << test.getBits(13, 4) << endl;

    return 0;
}

