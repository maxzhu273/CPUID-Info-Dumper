#pragma once

#include "stdafx.h"

#include <vector> // std::vector

#include "CPUID_Output.h"

namespace CPUID_Info_Dumper
{
	class CacheDescriptorList
	{
		private:
		std::vector<int> cachesPresent;

		

		// Class Constructor ///////////////////////////////////////////////////
		public:
		CacheDescriptorList();



		// Methods /////////////////////////////////////////////////////////////
		public:
		std::vector<CPUID_Output> update();



		// Getters and Setters /////////////////////////////////////////////////
		std::vector<int> getVector();

		// Returns true if cacheDescriptor is present on the CPU
		bool isCacheDescriptorPresent(int cacheDescriptor);
	};
}