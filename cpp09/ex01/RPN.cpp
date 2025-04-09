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

bool RPN::checkStr(const std::string &str)
{
	int stackSize = 0;
	if (str.length() < 2)
		return false;
	std::stringstream ss(str);
	std::string token;
	while (ss >> token)
	{
		try {
			int num = std::stoi(token);
			if (num < -9 || num > 9) {
				std::cerr << "Number should be between -9 and 9" << std::endl;
				return false;
			}
			stackSize++;
		}
		catch (const std::invalid_argument& e)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				if (stackSize < 2)
				{
					std::cerr << "Need minimum 2 numbers in stack before an operator"
						<< std::endl;
					return false;
				}
			stackSize--;
			}
			else {
				std::cerr << "Error" << std::endl;
				return false;
			}
		}
	}
	if (stackSize != 1) {
		std::cerr << "Error: invalid input, final stack size should be 1";
		return false;
	}
	return true;
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
			if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
			{
				std::cerr << "Resulting number is overflowing" << std::endl;
				return;
			}
			_stack.push(result);
		}
	}
	std::cout << _stack.top() << std::endl;
}