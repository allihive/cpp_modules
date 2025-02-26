#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	std::cout << "----- My tests ------" << std::endl;
	float x = 8.0f;
	float y = 9.0f;
	double de = 79.0;
	double e = 70.0;
	std::cout << "float" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
	std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;
	::swap(de, e);
	std::cout << "de = " << de << ", e = " << e << std::endl;
	std::cout << "min( de, e ) = " << ::min( de, e ) << std::endl;
	std::cout << "max( de, e ) = " << ::max( de, e ) << std::endl;
	
	std::cout << "DOUBLE" << std::endl;
	std::cout << "de = " << de << ", e = " << e << std::endl;
	std::cout << "min( de, e ) = " << ::min( de, e ) << std::endl;
	std::cout << "max( de, e ) = " << ::max( de, e ) << std::endl;
	::swap(de, e);
	std::cout << "de = " << de << ", e = " << e << std::endl;
	std::cout << "min( de, e ) = " << ::min( de, e ) << std::endl;
	std::cout << "max( de, e ) = " << ::max( de, e ) << std::endl;

	return 0;
}