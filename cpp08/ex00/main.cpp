#include "easyfind.hpp"
#include <deque>

int main()
{
	std::cout << "-----VECTOR-----" << std::endl;
	std::vector<int> intVec = {34, 12, 22, 56};
	for (auto i : intVec )
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	try{
		std::cout << "* Number in array *" << std::endl;
		auto it = easyfind(intVec, 22);
		std::cout << "Number found: " << *it << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "* Number not in array *" << std::endl;
		easyfind(intVec, -2147483648);
		std::cout << "Number not found" << std::endl;
	}
	catch(const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----DEQUE-----" << std::endl;
	std::deque<int> intDeq = {1, 2, 3, 4};
	for (auto i : intDeq )
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	try{
		std::cout << "* Number in array *" << std::endl;
		auto it = easyfind(intDeq, 22);
		std::cout << "Number found: "<< *it  << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "* Number not in array *" << std::endl;
		easyfind(intDeq, -2147483648);
		std::cout << "Number not found" << std::endl;
	}
	catch(const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}