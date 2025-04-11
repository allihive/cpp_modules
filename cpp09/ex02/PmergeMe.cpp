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

std::vector<int> &PmergeMe::getVector() {
	return this->_vectorList;
}

std::deque<int> &PmergeMe::getDeque() {
	return this->_dequeList;
}

bool PmergeMe::duplicatesVec(std::vector<int> &vec, int num)
{
	for (const auto n : vec) {
		if (num == n)
			return false;
	}
	return true;
}

void printVec(std::vector<int> &vec) {
	for (auto const &num : vec) {
		std::cout << num << " ";
	}
}

bool PmergeMe::convertNumbers(const std::string &arg) {
	size_t i = 0;
	while (i < arg.length()) {
		if (!isdigit(arg[i])) {
			std::cerr << "Positive numbers only!" << std::endl;
			return false;
		}
		i++;
	}
	try {
		int num = stoi(arg);

		if (!duplicatesVec(_vectorList, num) || !duplicatesDeq(_dequeList, num)) {
			std::cerr << "We do not allow duplicates here" << std::endl;
			return false;
		}
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

std::vector<int> createJacobSequence(int pairSize) {
	std::vector<int> seq;
	int first = 1;
	int second = 3;
	seq.push_back(first);
	seq.push_back(second);
	for (int i = 2; i < pairSize; i++) {
		int nextValue = seq[i - 1] + seq[i - 2] * 2;
        seq.push_back(nextValue);
	}
	return seq;
}

void PmergeMe::insertJacobsthalVec(std::vector<int> &vec, std::vector<std::pair<int, int>> pairs)
{
	int pairSize = pairs.size();
	if (pairSize < 2)
		return;
	
	//create a vector of the sequence to determine the index of numbers
	std::vector<int> jacobseq = createJacobSequence(pairSize);
	std::vector<int> vecOrder  = vec; //copy to keep original order to vec

	int bNum;
	int aNum = vec[0];
	for (const auto& p : pairs) {
		if (aNum == p.first) {
			bNum = p.second;
			std::cout << "bNum: " << bNum << std::endl;
			break;
		}
	}
	vec.insert(vec.begin(), bNum); // 3 elements in the vec
	for (size_t i = 1; i < jacobseq.size(); i++)
	{
		size_t last = jacobseq[i - 1];
		size_t current = jacobseq[i];

		for (size_t seq = current; last <= seq && seq >= 0; seq--) //> !=
		{
			if (seq > pairs.size())
				continue;

			int a = vecOrder[seq];
			int b = -1;
			for (const auto &p : pairs) {
				if (a == p.first)
				{
					b = p.second;
					break;
					std::cout << "p.second: " << p.second << std::endl;
					std::cout << b << std::endl;
				}
			}
			auto pos = std::lower_bound(vec.begin(), vec.end(), b); //inserting b into a sorted a stack
			if (b != -1)
				vec.insert(pos, b);
		}
	}
}


void PmergeMe::sortVector(std::vector<int> &vec) {
	
	bool oddNumber = false;
	int leftOver = 0;

	if (vec.size() <= 1)
		return ;

	std::vector<std::pair<int, int>> pairs; //create pairs for vector
	if (vec.size() % 2 != 0)
	{
		oddNumber = true;
		leftOver = vec.back();
	}
	for (size_t i = 0; i + 1 < vec.size(); i += 2) //push the pair into the pairs vector will need to increase the loop by 2
	{
		if (vec[i] < vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
		pairs.emplace_back(vec[i], vec[i + 1]); //now a1 is bigger and placed into the vector of pairs
	}
	std::cout << "printing pairs: ";
	for (const auto& p : pairs) {
			std::cout << "(" << p.first << ", " << p.second << ") ";
		}
	std::cout << std::endl;
	if (pairs.size() == 1) {
		if (vec.size() == 2) {
 			if (vec[0] > vec[1])
				std::swap(vec[0], vec[1]);
		}
	}
	std::vector<int> aNum;
	for (const auto& a1 : pairs) {
		aNum.push_back(a1.first);
	}
	insertJacobsthalVec(aNum, pairs);
	std::cout << "aNum Vector after jacobs: ";
	printVec(aNum);
	std::cout << std::endl;
	if (oddNumber == true) //check the leftover
	{
		auto pos = std::lower_bound(aNum.begin(), aNum.end(), leftOver);
		aNum.insert(pos, leftOver);
	}
	vec = aNum; //copy the sorted vector into the main vector

}


/*DEQUE*/

bool PmergeMe::duplicatesDeq(std::deque<int> &deq, int num)
{
	for (const auto n : deq) {
		if (num == n)
			return false;
	}
	return true;
}