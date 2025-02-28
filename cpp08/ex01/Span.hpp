#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

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

		void	addNumber(unsigned int N);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
		unsigned int		getMaxN();
};