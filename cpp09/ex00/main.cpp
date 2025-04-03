#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Format error: ./btc <input file>" << std::endl;
		return (-1);
	}
	try {
		Bitcoin bit;
		bit.parseInputFile(argv[1]);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}