#pragma once

#include <iostream>
#include <vector>

class Span {
	private:
		unsigned int _max;
		std::vector<int> _arr;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		std::vector<int>	addNumber(unsigned int N);
		unsigned int		shortestSpan(std::vector<int>, std::vector<int>);
		unsigned int		longestSpan(std::vector<int>)
}