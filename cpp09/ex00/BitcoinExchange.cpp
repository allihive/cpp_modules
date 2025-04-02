#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::~Bitcoin() {}

Bitcoin &Bitcoin::operator=(const Bitcoin &other) {
	if (this != &other)
		other._data;
	return *this;
}

Bitcoin::Bitcoin(const Bitcoin &other) : _data(other._data) {}

bool validateFiles(std::string)
{
	
}