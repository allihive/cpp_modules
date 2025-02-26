#include "iter.hpp"

int main()
{
	std::string strings[] = {"hello", "my", "name", "is", "Alice"};
	char	chars[] = {'a', 'b', 'c', 'd'};
	int		ints[] = {1, 2, 3, 4};
	float	floats[] = {10.0f, 14.67f, 12.89f, 56.89f};

	std::cout << "\n------Strings array------" << std::endl;
	iter(strings, 5, printArr);

	std::cout << "\n------Char array------" << std::endl;
	iter(chars, 4, printArr);

	std::cout << "\n------Ints array------" << std::endl;
	iter(ints, 4, printArr);
	std::cout << "\nAfter increase\n" << std::endl;
	iter(ints, 4, increaseArr);
	iter(ints, 4, printArr);

	std::cout << "\n------Floats array------" << std::endl;
	iter(floats, 4, printArr);
	std::cout << "\nAfter increase\n" << std::endl;
	iter(floats, 4, increaseArr);
	iter(floats, 4, printArr);
} 