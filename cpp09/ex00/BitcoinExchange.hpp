#pragma once

#include <iostream>
#include <map>
#include <regex>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
#include <filesystem>

class Bitcoin {
	public:
		Bitcoin();
		~Bitcoin();
		Bitcoin& operator=(const Bitcoin&);
		Bitcoin (const Bitcoin&);

		int oYear;
		int lYear;
		int oMonth;
		int lMonth;
		int oDay;
		int lDay;
		
		void parsecsv(std::ifstream&);
		void parseInputFile(const std::string &file);
		bool isValiDate(const std::string &date);
		bool checkDate(int yr, int mo, int day);
		double calculateExchange(std::string line, float value);
		// void printResult(std::string date, double value, double result);

	private:
		std::map<std::string, float> _data;
		std::string _oldestDate;
		std::string _latestDate;
		
};