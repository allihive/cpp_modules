#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <chrono>

class PmergeMe {
	private:
		std::vector<int> _vectorList;
		std::deque<int> _dequeList;
		std::vector<int> _jacobSeq;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);

		void sortVector(std::vector<int> &vec);
		void sortDeque(std::deque<int> &deq);
		bool convertNumbers(const std::string &);

		// std::chrono::duration<double, std::micro> timeVector();
		// std::chrono::duration<double, std::micro> timeDeque();

};