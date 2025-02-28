#pragma once

#include <iostream>

template<typename T>
void printArr(T& item)
{
	std::cout << item << std::endl;
}
template<typename T>
void increaseArr(T& item)
{
	item++;
}

template<typename T>
void iter(T* arr, size_t len, void(*f)(T&))
{
	for (size_t i = 0; i < len; i++)
	{
		(*f)(arr[i]);
	}
}
template<typename T>
void iter(const T* arr, size_t len, void(*f)(const T&)) {
    for (size_t i = 0; i < len; i++) {
        (*f)(arr[i]);
    }
}