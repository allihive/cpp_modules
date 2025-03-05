#pragma once

#include <iostream>
#include <stack>
// #include <list>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() {}
		~MutantStack() {}
		MutantStack(const MutantStack& other) {
			this = other;
		};
		MutantStack& operator=(const MutantStack& other) {
			if (this != other)
				std::stack<T, Container>::operator=(other); 
			return *this;
		};

		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;

		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
		const_iterator begin() const {
			return this->c.begin();
		}
		const_iterator end() const {
			return this->c.end();
		}
};

