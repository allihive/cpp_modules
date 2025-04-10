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

		//check for duplicates here
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

//write insertjacobsthal numbers
//create a vector of the sequence to determine the index of numbers
//create the sequence by checking the amount of pairs there are
//find the first pair in the main vector (b1) and insert
	//will insert it at the first place because it's naturally smaller
//go through the sequence size
	//sequence i (ex. 5)
	//sequence i-1 (the last number that was in the sequence) (ex. 3)
	//find the pair, based off index of the first number (like a map)
	//find the position to insert using lower bound?
	//then insert

void PmergeMe::sortVector(std::vector<int> &vec) {
	
	bool oddNumber = false;

	if (vec.size() <= 1)
		return ;
	std::vector<std::pair<int, int>> pairs; //create pairs for vector
	for (size_t i = 0; i < vec.size() / 2; i += 2)
	{
		if (vec[i] < vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
		pairs.emplace_back(vec[i], vec[i + 1]); //now a1 is bigger and placed into the vector of pairs
	}
	if (vec.size() % 2 != 0)
	{
		oddNumber = true;
		int leftOver = vec.back();
	}
	
	//push the pair into the pairs vector will need to increase the loop by 2
	//create a vector for large numbers (a) 
	//call the vec algo again
	//insert using jacobsthal
	//check the leftover
		//find the position to insert
	//main vector will now be large numbers

}