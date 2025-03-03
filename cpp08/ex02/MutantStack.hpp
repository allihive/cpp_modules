#pragma once

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() : std::stack<T, container> {};
		~MutantStack() : std::stack<T, container> {};
		MutantStack(const MutantStack& other) {
			this* = other;
		};
		MutantStack& operator=(const MutantStack& other) {
			if (this != other)
				std::stack<T, Container>::operator=(other);
			return *this;
		};

		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;
};

