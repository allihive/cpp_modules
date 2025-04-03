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
		void parsecsv(std::ifstream&);
		void parseInputFile(const std::string &file);
		bool isValiDate(const std::string &date);
	private:
		std::map<std::string, float> _data;
		std::string _oldestDate;
		std::string _latestDate;
};