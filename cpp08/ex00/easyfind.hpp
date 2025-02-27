#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
typename T::iterator easyfind(T& container, int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw (std::runtime_error("Value not in container"));
	return it;
}