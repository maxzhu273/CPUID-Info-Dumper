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

	Register test = Register(0x12345678);
	cout << bitset<32>(test.getValue()) << endl;
	cout << bitset<32>(test.getBits(5, 7)) << endl;
	cout << test.isBitSet(0) << endl;


    return 0;
}

