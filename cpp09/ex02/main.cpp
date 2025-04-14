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
		std::cout << "Before: ";
		printVec(pmerge.getVector());
		

		auto startVec = std::chrono::high_resolution_clock::now();
		pmerge.sortVector(pmerge.getVector());
		auto endVec = std::chrono::high_resolution_clock::now();
		auto durationVec = std::chrono::duration<double, std::micro>(endVec - startVec);

		std::cout << "After: ";
		printVec(pmerge.getVector());

		auto startDeq = std::chrono::high_resolution_clock::now();
		pmerge.sortDeque(pmerge.getDeque());
		auto endDeq = std::chrono::high_resolution_clock::now();
		auto durationDeq = std::chrono::duration<double, std::micro>(endDeq - startDeq);
		
		// std::cout << "After Deq: ";
		// printDeq(pmerge.getDeque());

		std::cout << "Time to process a range of " << argc - 1
			<< " with Vector : " << std::fixed << std::setprecision(5) << durationVec.count() << " us" << std::endl;
		std::cout << "Time to process a range of " << argc - 1
			<< " with Deque : " << std::fixed << std::setprecision(5) << durationDeq.count() << " us" << std::endl;
	}
}