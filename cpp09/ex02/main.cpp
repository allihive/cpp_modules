#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 2) {
		PmergeMe pmerge;
		for (int i = 1; i < argc; i++)
		{
			if (pmerge.convertNumbers(argv[i]) == false)
				return 1;
		}
		auto startVec = std::chrono::high_resolution_clock::now();
		std::cout << "Before: " << std::endl;
		printVec(pmerge.getVector());
		pmerge.sortVector(pmerge.getVector());
		auto endVec = std::chrono::high_resolution_clock::now();
		auto durationVec = std::chrono::duration_cast<std::chrono::microseconds>(endVec - startVec);
		
		std::cout << "After: " << std::endl;
		printVec(pmerge.getVector());
		std::cout << "Time to process a range of " << argc - 1
			<< " with Vector : " << durationVec.count() << " us" << std::endl;
	}
}