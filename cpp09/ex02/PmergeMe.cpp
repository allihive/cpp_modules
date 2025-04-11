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
	std::cout << std::endl;
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

std::vector<int> createJacobSequenceVec(int pairSize) {
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
	std::vector<int> jacobseq = createJacobSequenceVec(pairSize);
	std::vector<int> vecOrder  = vec; //copy to keep original order to vec

	int bNum;
	int aNum = vec[0];
	for (const auto& p : pairs) {
		if (aNum == p.first) {
			bNum = p.second;
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
	if (pairs.size() == 1) {
		if (vec.size() < 4) {
 			if (vec[0] > vec[1]) {
				std::swap(vec[0], vec[1]);
				if (oddNumber == true) {
					vec.pop_back();
					auto pos = std::lower_bound(vec.begin(), vec.end(), leftOver);
					vec.insert(pos, leftOver);
				return;
				}
			}
		}
	}
	std::vector<int> aNum;
	for (const auto& a1 : pairs) {
		aNum.push_back(a1.first);
	}
	insertJacobsthalVec(aNum, pairs);
	if (oddNumber == true ) //check the leftover
	{
		auto pos = std::lower_bound(aNum.begin(), aNum.end(), leftOver);
		aNum.insert(pos, leftOver);
	}
	vec = aNum; //copy the sorted vector into the main vector
}


/*DEQUE*/

std::deque<int> createJacobSequenceDeq(int pairSize) {
	std::deque<int> seq;
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

bool PmergeMe::duplicatesDeq(std::deque<int> &deq, int num)
{
	for (const auto n : deq) {
		if (num == n)
			return false;
	}
	return true;
}

void PmergeMe::insertJacobsthalDeq(std::deque<int> &deq, std::deque<std::pair<int, int>> pairs)
{
	int pairSize = pairs.size();
	if (pairSize < 2)
		return;
	
	//create a deque of the sequence to determine the index of numbers
	std::deque<int> jacobseq = createJacobSequenceDeq(pairSize);
	std::deque<int> deqOrder  = deq; //copy to keep original order to deq

	int bNum;
	int aNum = deq[0];
	for (const auto& p : pairs) {
		if (aNum == p.first) {
			bNum = p.second;
			break;
		}
	}
	deq.insert(deq.begin(), bNum); // 3 elements in the deq
	for (size_t i = 1; i < jacobseq.size(); i++)
	{
		size_t last = jacobseq[i - 1];
		size_t current = jacobseq[i];

		for (size_t seq = current; last <= seq && seq >= 0; seq--) //> !=
		{
			if (seq > pairs.size())
				continue;

			int a = deqOrder[seq];
			int b = -1;
			for (const auto &p : pairs) {
				if (a == p.first)
				{
					b = p.second;
					break;
				}
			}
			auto pos = std::lower_bound(deq.begin(), deq.end(), b); //inserting b into a sorted a stack
			if (b != -1)
				deq.insert(pos, b);
		}
	}
}


void PmergeMe::sortDeque(std::deque<int> &deq) {
	
	bool oddNumber = false;
	int leftOver = 0;

	if (deq.size() <= 1)
		return ;

	std::deque<std::pair<int, int>> pairs; //create pairs for deque
	if (deq.size() % 2 != 0)
	{
		oddNumber = true;
		leftOver = deq.back();
	}
	for (size_t i = 0; i + 1 < deq.size(); i += 2) //push the pair into the pairs deque will need to increase the loop by 2
	{
		if (deq[i] < deq[i + 1])
			std::swap(deq[i], deq[i + 1]);
		pairs.emplace_back(deq[i], deq[i + 1]); //now a1 is bigger and placed into the deque of pairs
	}
	if (pairs.size() == 1) {
		if (deq.size() < 4) {
 			if (deq[0] > deq[1]) {
				std::swap(deq[0], deq[1]);
				if (oddNumber == true) {
					deq.pop_back();
					auto pos = std::lower_bound(deq.begin(), deq.end(), leftOver);
					deq.insert(pos, leftOver);
				return;
				}
			}
		}
	}
	std::deque<int> aNum;
	for (const auto& a1 : pairs) {
		aNum.push_back(a1.first);
	}
	insertJacobsthalDeq(aNum, pairs);
	if (oddNumber == true ) //check the leftover
	{
		auto pos = std::lower_bound(aNum.begin(), aNum.end(), leftOver);
		aNum.insert(pos, leftOver);
	}
	deq = aNum; //copy the sorted deque into the main vector
}