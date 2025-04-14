#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <chrono>
#include <iomanip>

class PmergeMe {
	private:
		std::vector<int> _vectorList;
		std::deque<int> _dequeList;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);

		void sortVector(std::vector<int> &vec);
		void sortDeque(std::deque<int> &deq);
		bool convertNumbers(const std::string &);
		bool duplicatesVec(std::vector<int> &vec, int num);
		bool duplicatesDeq(std::deque<int> &deq, int num);

		void insertJacobsthalVec(std::vector<int> &main, std::vector<std::pair<int, int>> pairs);
		void insertJacobsthalDeq(std::deque<int> &main, std::deque<std::pair<int, int>> pairs);
		std::vector<int> &getVector();
		std::deque<int> &getDeque();
};

void printVec(std::vector<int> & vec);
void printDeq(std::deque<int> &deq);