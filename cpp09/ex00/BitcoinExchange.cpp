#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {
	
}

Bitcoin::~Bitcoin() {}

Bitcoin &Bitcoin::operator=(const Bitcoin &other) {
	if (this != &other)
		other._data;
	return *this;
}

Bitcoin::Bitcoin(const Bitcoin &other) : _data(other._data) {}

bool Bitcoin::parsecsv(std::string csvfile)
{
	if (csvfile == "data.csv")
	{
		std::ifstream csvdata("data.csv");
		if (!csvdata)
		{
			throw std::runtime_error("failed to open data.csv");
		}
		std::string line;
		while (std::getline(csvdata, line)){
			std::stringstream ss(line);
			std::string key;
			double value;
			if (std::getline(ss, key, ',') && (ss >> value))
				_data[key] = value;
			else
				std::cerr << "invalid format in data.csv" << std::endl;
		}
		

	}
	return false;
}