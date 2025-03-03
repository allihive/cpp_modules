#include "Span.hpp"

int main()
{
	std::cout << "------subject test------" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "------over size limit------" << std::endl;
	try
	{
		Span span = Span(3);
		span.addNumber(5);
		span.addNumber(8);
		span.addNumber(56);
		span.addNumber(23);
		span.addNumber(25);
		span.addNumber(254);
		std::cout << "* not over size limit *" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<<  e.what() << '\n';
	}
	std::cout << "------under size limit longest span------" << std::endl;
	try
	{
		Span span = Span(1);
		span.addNumber(5);
		std::cout << "* longest span incorrect*" << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<<  e.what() << '\n';
	}
	
	std::cout << "------test large vector------" << std::endl;
	try
	{
		Span sp = Span(10000);
		std::srand(time(0));
		for(size_t i = 0; i < sp.getMaxN(); i++)
		{
			sp.addNumber(rand());
		}
		std::cout << "min value: " << sp.getMinValue() << std::endl;
		std::cout << "max value: " << sp.getMaxValue() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}

}