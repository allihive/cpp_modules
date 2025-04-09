#include "PmergeMe.hpp"

PmergeMe:: PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	_dequeSort = other._dequeSort;
	_vectorSort = other._vectorSort;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other)
	{
		_dequeSort = other._dequeSort;
		_vectorSort = other._vectorSort;
	}
	return (*this);
}

bool PmergeMe::convertNumbers(const std::string &arg) {
	int i = 0;
	while (i < arg.length()) {
		if (!isdigit(arg[i])) {
			std::cerr << "Positive numbers only!" << std::endl;
			return false;
		}
		i++;
	}
	try {
		int num = stoi(arg);

		if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		{
			std::cerr << "Number too large" << std::endl;
			return false;
		}
		_dequeSort.push_back(num);
		_vectorSort.push_back(num);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
}