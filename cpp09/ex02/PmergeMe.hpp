#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <limits>

class PmergeMe {
	private:
		std::vector<int> _vectorList;
		std::deque<int> _dequeList;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);

		void sortVector();
		void sortDeque();
		bool convertNumbers(const std::string &);
		void getTime()

};