#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Format error: ./btc <input file>" << std::endl;
	}
	Bitcoin bit;

	bit.parseInputFile(argv[1]);
}