#pragma once
#include <stack>
#include <iostream>
#include <sstream>

class RPN {
	private:
		std::stack<double> _stack;
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN &other);

		void calculator(const std::string& );
		bool checkStr(const std::string &);
};