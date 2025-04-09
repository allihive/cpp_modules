#include "PmergeMe.hpp"

PmergeMe:: PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	_dequeList = other._dequeList;
	_vectorList = other._vectorList;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other)
	{
		_dequeList = other._dequeList;
		_vectorList = other._vectorList;
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

		_dequeList.push_back(num);
		_vectorList.push_back(num);
		return true;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
	return true;
}

void PmergeMe::sortVector() {

}