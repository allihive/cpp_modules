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
// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[0] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL - 1] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }