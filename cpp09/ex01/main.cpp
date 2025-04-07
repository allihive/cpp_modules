#include "RPN.hpp"

int main(int argc, char **argv) 
{
	if (argc == 2)
	{
		RPN::calculator(argv[1]);
	}
	return 1;
}