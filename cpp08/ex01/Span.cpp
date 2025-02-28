#include "Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(unsigned int N) : _max(N) {}

Span::Span(const Span& other)
{
	this->_max = other._max;
	this->_arr = other._arr;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_max = other._max;
		this->_arr = other._arr;
	}
	return *this;
}

unsigned int Span::getMaxN()
{
	return this->_max;
}
void Span::addNumber(unsigned int N)
{
	unsigned int size = _arr.size();
	if (size == this->_max)
	{
		std::length_error("Maximum size of the vector reached");
	}
	_arr.push_back(N);
}
unsigned int Span::longestSpan()
{
	if (_arr.size() < 2)
		std::length_error("Not enough elements added");
	unsigned int min = *std::min_element(_arr.begin(), _arr.end());
	unsigned int max = *std::max_element(_arr.begin(), _arr.end());
	return (max - min);
}
unsigned int Span::shortestSpan()
{
	std::vector<int> sortVec = this->_arr;
	std::sort(sortVec.begin(), sortVec.end());

	unsigned int min = *std::max_element(sortVec.begin(), sortVec.end()) + 1;
	for (size_t i = 0; i < sortVec.size(); i++)
	{
		auto tmp = sortVec[i] - sortVec[i - 1];
		if (tmp < min)
			min = tmp;
	}
	return (min);
	//subtract the bigger one from the smaller one and check if it's bigger or smaller
}