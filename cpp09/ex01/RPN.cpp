#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
	_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}

void RPN::calculator(const std::string &str)
{
	if (checkStr(str) == false)
		return;
	double result = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i])) {
			double n = str[i] - '0'; //convert to int
			_stack.push(n);
		}
		else if (str[i] == ' ')
		 	continue;
		else {
			double first = _stack.top();
			_stack.pop();
			double second = _stack.top();
			_stack.pop();
			if (str[i] == '/' && first == 0)
			{
				std::cout << "Cannot divide by 0" << std::endl;
				return;
			}
			if (str[i] == '/')
				result = second / first;
			else if (str[i] == '+')
				result = second + first;
			else if (str[i] == '-')
				result = second - first;
			else if (str[i] == '*')
				result = second * first;
			if (result > INT_MAX || result < INT_MIN)
			{
				std::cerr << "Resulting number is overflowing" << std::endl;
				return;
			}
			_stack.push(result);
		}
	}
}


// no numbers greater than 10
// +-*/ only
//