#include "RPN.hpp"

int main(int argc, char **argv) 
{
	if (argc == 2)
	{
		RPN rpn;
		rpn.calculator(argv[1]);
		return 0;
	}
	else {
		std::cerr << "Invalid input: './RPN 6 5 *'" << std::endl;
		return 1;
	}
}