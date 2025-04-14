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

void printDeq(std::deque<int> &deq) {
	for (auto const &num : deq) {
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

std::vector<double> createJacobSequenceVec(int pairSize) {
	std::vector<double> seq;
	double first = 1;
	double second = 3;
	seq.push_back(first);
	seq.push_back(second);

	double nextValue = 3;
	for (double i = 2; nextValue < pairSize; i++) {
		nextValue = seq[i - 1] + seq[i - 2] * 2;
        seq.push_back(nextValue);
	}
	return seq;
}

void PmergeMe::insertJacobsthalVec(std::vector<int> &vec, std::vector<std::pair<int, int>> pairs)
{
	int pairSize = pairs.size();
	
	//create a vector of the sequence to determine the index of numbers
	std::vector<double> jacobseq = createJacobSequenceVec(pairSize);
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
	if (pairSize < 2){
		return;
	}
	for (size_t i = 1; i < jacobseq.size(); i++)
	{
		size_t last = jacobseq[i - 1];
		size_t current = jacobseq[i];

		for (size_t seq = current; last <= seq ; seq--) //> != && seq < vecOrder.size()
		{
			if (seq > pairs.size()){
				continue;
			}
			int a = vecOrder[seq - 1];
			int b = -1;
			for (const auto &p : pairs) {
				if (a == p.first)
				{
					b = p.second;
					break;
				}
			}
			auto pos = std::lower_bound(vec.begin(), vec.end(), b); //inserting b into a sorted a stack
			if (b != -1 && std::find(vec.begin(), vec.end(), b) == vec.end()) // && std::find(vec.begin(), vec.end(), b) == vec.end()
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
	std::vector<int> aNum;
	for (const auto& a : pairs) {
		aNum.push_back(a.first);
	}
	sortVector(aNum);
	insertJacobsthalVec(aNum, pairs);
	if (oddNumber == true ) //check the leftover
	{
		auto pos = std::lower_bound(aNum.begin(), aNum.end(), leftOver);
		aNum.insert(pos, leftOver);
	}
	vec = aNum; //copy the sorted vector into the main vector
}


/*DEQUE*/
std::deque<double> createJacobSequenceDeq(int pairSize) {
	std::deque<double> seq;
	double first = 1;
	double second = 3;
	seq.push_back(first);
	seq.push_back(second);
	double nextValue = 3;
	for (double i = 2; nextValue < pairSize; i++) {
		nextValue = seq[i - 1] + seq[i - 2] * 2;
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
	
	//create a deque of the sequence to determine the index of numbers
	std::deque<double> jacobseq = createJacobSequenceDeq(pairSize);
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
	if (pairSize < 2){
		return;
	}
	for (size_t i = 1; i < jacobseq.size(); i++)
	{
		size_t last = jacobseq[i - 1];
		size_t current = jacobseq[i];

		for (size_t seq = current; last <= seq ; seq--) //> != && seq < deqOrder.size()
		{
			if (seq > pairs.size()){
				continue;
			}
			int a = deqOrder[seq - 1];
			int b = -1;
			for (const auto &p : pairs) {
				if (a == p.first)
				{
					b = p.second;
					break;
				}
			}
			auto pos = std::lower_bound(deq.begin(), deq.end(), b); //inserting b into a sorted a stack
			if (b != -1 && std::find(deq.begin(), deq.end(), b) == deq.end()) // && std::find(deq.begin(), deq.end(), b) == deq.end()
				deq.insert(pos, b);
			
		}
	}
}

void PmergeMe::sortDeque(std::deque<int> &deq) {
	
	bool oddNumber = false;
	int leftOver = 0;

	if (deq.size() <= 1)
		return ;
	std::deque<std::pair<int, int>> pairs; //create pairs for Deque

	if (deq.size() % 2 != 0)
	{
		oddNumber = true;
		leftOver = deq.back();
	}
	for (size_t i = 0; i + 1 < deq.size(); i += 2) //push the pair into the pairs Deque will need to increase the loop by 2
	{
		if (deq[i] < deq[i + 1])
			std::swap(deq[i], deq[i + 1]);
		pairs.emplace_back(deq[i], deq[i + 1]); //now a1 is bigger and placed into the Deque of pairs
	}
	std::deque<int> aNum;
	for (const auto& a : pairs) {
		aNum.push_back(a.first);
	}
	sortDeque(aNum);
	insertJacobsthalDeq(aNum, pairs);
	if (oddNumber == true ) //check the leftover
	{
		auto pos = std::lower_bound(aNum.begin(), aNum.end(), leftOver);
		aNum.insert(pos, leftOver);
	}
	deq = aNum; //copy the sorted vector into the main vector
}