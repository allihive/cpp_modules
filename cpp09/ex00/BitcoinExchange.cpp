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
		_data = other._data;
	return *this;
}

Bitcoin::Bitcoin(const Bitcoin &other) : _data(other._data) {}

void Bitcoin::parsecsv(std::ifstream &csvfile)
{
	std::string line;
	std::getline(csvfile, line);
	while (std::getline(csvfile, line))
	{
		std::stringstream ss(line);
		std::string key, valueStr;
		double value = 0;
		std::getline(ss, key, ',') && std::getline(ss, valueStr);
		try {
			value = std::stod(valueStr);
			_data[key] = value;
		}
		catch (std::exception &e)
		{
			std::cerr << "invalid file: " << e.what() << std::endl;
		}
	}
	_oldestDate = _data.begin()->first;
	oYear = std::stoi(_oldestDate.substr(0, 4));
	oMonth = std::stoi(_oldestDate.substr(5, 7));
	oDay = std::stoi(_oldestDate.substr(8, 10));
	_latestDate = _data.rbegin()->first;
	lYear = std::stoi(_latestDate.substr(0, 4));
	lMonth = std::stoi(_latestDate.substr(5, 7));
	lDay = std::stoi(_latestDate.substr(8, 10));

}
bool Bitcoin::isValiDate(const std::string &date)
{
	std::tm tm{}; //zero out the tm structure for garbage dates
	std::istringstream ss(date);

	char dash1, dash2;
	int yr, mo, dy;

	if (!(ss >> yr >> dash1 >> mo >> dash2 >> dy) || (dash1 != '-' && dash2 != '-'))
		return false;
	tm.tm_year = yr - 1900; //tm starts at 1900
	tm.tm_mon = mo - 1;
	tm.tm_mday = dy;
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;

	std::time_t inputDate = std::mktime(&tm);
	if (inputDate == -1)
		return false;
	std::time_t now = std::time(nullptr); //gets current time
	std::tm *now_tm = std::gmtime(&now);
	now_tm->tm_hour = 0;
	now_tm->tm_min = 0;
	now_tm->tm_sec = 0;
	std::time_t today = std::mktime(now_tm);
	if (inputDate > today) {
		std::cerr << date << " is a future date." << std::endl;
		return false;
	}
	if (!checkDate(yr, mo, dy)) {
		std::cerr << date << " date is not within our database" << std::endl;
		return false;
	}
	return (true);
}

void Bitcoin::parseInputFile(const std::string& file)
{
	std::string line;
	std::ifstream input(file);
	std::smatch matches;
	std::regex pattern(R"(^(\d{4}-\d{2}-\d{2})\s\|\s(-?\d+(\.\d+)?)$)");

	if (!input.is_open())
		throw std::runtime_error("Failed to open file");
	if (std::filesystem::is_empty(file))
		throw std::runtime_error("Empty file");
	
	std::getline(input, line);
	while (std::getline(input, line))
	{
		if (!std::regex_match(line, matches, pattern)
			|| isValiDate(matches[1].str()) == false)
		{
			std::cout << "Error: bad input => " << line << std::endl;
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
		double result = calculateExchange(fullDate, value);
		if (result == -1) {
			std::cout << "Not able to calcuate exchange" << std::endl;
			return;
		}
		std::cout << fullDate << " => " << value << " = " << result << std::endl;
	}
}

bool Bitcoin::checkDate(int yr, int mo, int day) 
{
	if (yr > lYear || yr < oYear)
		return false;
	else if (yr == oYear) {
		if (mo < oMonth )
			return false;
		else if (mo == oMonth) {
			if (day < oDay) {
				return false;
			}
		}
		return true;
	}
	else if (yr == lYear) {
		if (mo > lMonth)
		{
			
			std::cout << "exited at lmonth: " << lMonth << std::endl;
			return false;
		}
		else if (mo == lMonth) {
			if (day > lDay) {
				std::cout << "exited at lday" << std::endl;
				return false;
			}
		}
		return true;
	}
	return true;
}


double Bitcoin::calculateExchange(std::string date, float value)
{
	std::string closestDate;

	std::map<std::string, float>::iterator it = _data.lower_bound(date);
	if (it == _data.end())
		it--;
	else if (it->first > date) {
		if (it == _data.begin())
			return -1;
		it--;
	} 
	return	(it->second * value);
}

