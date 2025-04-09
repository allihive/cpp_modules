#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 2) {
		PmergeMe pmerge;
		for (size_t i = 0; i < argc - 1; i++)
		{
			if (pmerge.convertNumbers(argv[i]) == false)
				return 1;
		}
		
	}
}