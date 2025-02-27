#include "Array.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	Array<int> intArr(5); //creating this class
	int * random = new int[5]; //creating a random one to compare
	
	std::cout << "------Subject test-------" << std::endl;
	srand(time(NULL));
	for(size_t i = 0; i < intArr.size(); i++)
	{
		int value = rand();
		intArr[i] = value;
		random[i] = value;
	}
	for (size_t i = 0; i < intArr.size(); i++)
	{
		if (intArr[i] == random[i])
		{
			std::cout << "matching!" << std::endl;
			continue;
		}
		else
			std::cout << "Values are not the same!" << std::endl;
	}
	delete[] random;

	std::cout << "------Copy test-------" << std::endl;
	Array<std::string> strArray(4);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "just";
	strArray[3] = "kidding";
	Array<std::string> copy(strArray);
	
	std::cout << "* original string *" << std::endl;
	for (size_t i = 0; i < strArray.size(); ++i)
	{
		std::cout << strArray[i] << std::endl;
	}
	std::cout << "* copy string *" << std::endl;
	for (size_t i = 0; i < copy.size(); ++i)
	{
		std::cout << copy[i] << std::endl;
	}
	
	std::cout << "* copy assignment operator *" << std::endl;
	Array<std::string> copyString = strArray;
	for (size_t i = 0; i < copyString.size(); i++)
	{
		std::cout << copyString[i] << std::endl;
	}

	std::cout << "* accessing out of bounds *" << std::endl;
	try {
		strArray[-2];
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	

	std::cout << "Size(): " << strArray.size() << std::endl;
	strArray.size();
}