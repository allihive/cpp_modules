#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {
	std::ifstream csvdata("data.csv");
	if (!csvdata.is_open())
	{
		throw std::runtime_error("failed to open data.csv");
	}
	parsecsv(csvdata);
}

Bitcoin::~Bitcoin() {}

Bitcoin &Bitcoin::operator=(const Bitcoin &other) {
	if (this != &other)
		other._data;
	return *this;
}

Bitcoin::Bitcoin(const Bitcoin &other) : _data(other._data) {}

void Bitcoin::parsecsv(std::ifstream &csvfile)
{
	std::string line;
	while (std::getline(csvfile, line))
	{
		std::stringstream ss(line);
		std::string key, valueStr;
		double value = 0;
		std::getline(ss, key);
		try {
			std::getline(ss, key, ',') && (ss >> valueStr);
			value = std::stod(valueStr);
			_data[key] = value;
		}
		catch (std::exception &e)
		{
			std::cerr << "invalid file: " << e.what() << std::endl;
		}
	}
	_oldestDate = _data.begin()->first;
	oyear = std::stoi(_oldestDate.substr(0, 4));
	_latestDate = _data.rbegin()->first;
	lyear = std::stoi(_latestDate.substr(0, 4));
}

void Bitcoin::parseInputFile(const std::string& file)
{
	std::string line;
	std::ifstream input(file);
	std::smatch matches;
	std::regex pattern(R"(^(\d{4}-\d{2}-\d{2})\s|\s(-?\d*\.\d+$))");
	int yr, mo, day;
	char dash1, dash2;

	if (!input.is_open())
		throw std::runtime_error("Failed to open file");
	if (std::filesystem::is_empty(file))
		throw std::runtime_error("Empty file");
	
	std::getline(input, line);
	while (std::getline(input, line))
	{
		if (!std::regex_match(line, matches, pattern)
			|| !isValiDate(matches[1].str()))
		{
			std::cout << "Error: bad input => " << matches[1] << std::endl;
			continue;
		}
		double value = stod(matches[2]);
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue; 
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		std::string fullDate = matches.str(1);
		std::istringstream ss(fullDate);
		ss >> yr >> dash1 >> mo >> dash2 >> day;
		if (!checkOldestAndLatest){
			std::cout << "The year is not within our database" << std::endl;
			return;
		}
		double result = calculateExchange(fullDate, value);
		if (result == -1) {
			std::cout << "Not able to calcuate exchange" << std::endl;
			return;
		}
		printResult(yr, mo, day, result);
	}
}

bool Bitcoin::checkOldestAndLatest(int yr) 
{
	if (yr > lyear || yr < oyear)
		return false;
	return true;
}

double Bitcoin::calculateExchange(std::string date, float value)
{
	std::string closestDate;
	std::map<std::string, float>::iterator it = _data.lower_bound(date);
	if (closestDate.empty())
		return -1;
	if (it == _data.end())
		it--;
	else if (it->first > date) {
		if (it == _data.begin())
			return -1;
		it--;
	} 
	return	(it->second * value);
}

bool isValiDate(const std::string &date)
{
	std::tm tm{}; //zero out the tm structure for garbage dates
	std::istringstream ss(date);

	char dash1;
	int yr, mo, dy;

	if (!(ss >> yr >> dash1 >> mo >> dash1 >> dy) || dash1 != '-')
		return false;
	tm.tm_year = yr - 1900; //tm starts at 1900
	tm.tm_mon = mo - 1;
	tm.tm_mday = dy;

	std::time_t t = std::mktime(&tm);
	if (t == -1)
		return false;
	return (tm.tm_year == yr && tm.tm_mon == mo && tm.tm_mday == dy);
}


