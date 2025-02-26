#include "Array.hpp"

int main()
{
	Array<int> intArr(5);
	
	intArr[0] = 0;
	intArr[1] = 1;
	intArr[2] = 2;
	intArr[3] = 3;
	intArr[4] = 4;

	int * a = new int[5];
	Array<int> copy(intArr);

	delete[] a;

}