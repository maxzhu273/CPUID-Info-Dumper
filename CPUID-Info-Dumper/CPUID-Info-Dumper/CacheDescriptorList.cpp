#include "stdafx.h"

#include <algorithm> // std::binary_search
#include <vector> // std::vector

#include "CacheDescriptorList.h"
#include "CPUID.h"
#include "CPUID_Output.h"
#include "Register.h"

namespace CPUID_Info_Dumper
{
	// Class Constructor ///////////////////////////////////////////////////////
	
	CacheDescriptorList::CacheDescriptorList()
	{
		this->cachesPresent = std::vector<int>();
	}




	// Methods /////////////////////////////////////////////////////////////////

	std::vector<CPUID_Output> CacheDescriptorList::update()
	{
		int currentIteration = 0;	// Number of times CPUID has been run
		int requiredIterations = 0;	// Number of times CPUID needs to be run

		std::vector<CPUID_Output> cpuidOutputVector = std::vector<CPUID_Output>();

		// Last byte of EAX is the number of times CPUID should be run.
		do
		{
			// Get CPUID
			cpuidOutputVector.push_back(CPUID::runCPUID(0x2));

			if (requiredIterations == 0)
			{
				requiredIterations = cpuidOutputVector.back().eax.getBits(0, 8);
			}


			// Add cache descriptors to the vector
			// Check if first bit of EAX is unset --> if unset, then the register contains valid 8-bit cache descriptors
			if (cpuidOutputVector.back().eax.isBitSet(31) == 0)
			{
				this->cachesPresent.push_back(cpuidOutputVector.back().eax.getBits(0, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().eax.getBits(8, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().eax.getBits(16, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().eax.getBits(24, 8));
			}

			// Check if first bit of EBX is unset --> if unset, then the register contains valid 8-bit cache descriptors
			if (cpuidOutputVector.back().ebx.isBitSet(31) == 0)
			{
				this->cachesPresent.push_back(cpuidOutputVector.back().ebx.getBits(0, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().ebx.getBits(8, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().ebx.getBits(16, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().ebx.getBits(24, 8));
			}

			// Check if first bit of ECX is unset --> if unset, then the register contains valid 8-bit cache descriptors
			if (cpuidOutputVector.back().ecx.isBitSet(31) == 0)
			{
				this->cachesPresent.push_back(cpuidOutputVector.back().ecx.getBits(0, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().ecx.getBits(8, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().ecx.getBits(16, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().ecx.getBits(24, 8));
			}

			// Check if first bit of EDX is unset --> if unset, then the register contains valid 8-bit cache descriptors
			if (cpuidOutputVector.back().edx.isBitSet(31) == 0)
			{
				this->cachesPresent.push_back(cpuidOutputVector.back().edx.getBits(0, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().edx.getBits(8, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().edx.getBits(16, 8));
				this->cachesPresent.push_back(cpuidOutputVector.back().edx.getBits(24, 8));
			}

			currentIteration++;
		} while (currentIteration < requiredIterations);

		// Sort the cache descriptors from largest to smallest
		std::sort(this->cachesPresent.rbegin(), this->cachesPresent.rend());

		// Remove null cache descriptors (0x0) -- All zeros should be at end of vector due to sort
		while (this->cachesPresent.back() == 0x0)
		{
			this->cachesPresent.pop_back();
		}

		// Shrink the vector
		this->cachesPresent.shrink_to_fit();

		return cpuidOutputVector;
	}





	// Getters and Setters /////////////////////////////////////////////////////
	std::vector<int> CacheDescriptorList::getVector()
	{
		return this->cachesPresent;
	}

	bool CacheDescriptorList::isCacheDescriptorPresent(int cacheDescriptor)
	{
		return std::binary_search(this->cachesPresent.rbegin(), this->cachesPresent.rend(), cacheDescriptor);
	}
}