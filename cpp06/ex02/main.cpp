/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:45:03 by alli              #+#    #+#             */
/*   Updated: 2025/02/19 09:49:45 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base* generate(void)
{
	int random = rand() % 3;
	
	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void identify(Base* p)
{
	if (A* a = dynamic_cast<A*> (p))
		std::cout << "Identified ptr as A" << std::endl;
	else if (B* b = dynamic_cast<B*> (p))
		std::cout << "Identified ptr as B" << std::endl;
	else if (C* c = dynamic_cast<C*> (p))
		std::cout << "Identified ptr as C" << std::endl;
	else
		std::cout << "Is not identifiable" << std::endl;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&> (p);
		std::cout << "Identified ref as A" << std::endl;
		(void)a;
	}
	catch (const std::bad_cast &e) {
	};
	try {
		B& b = dynamic_cast<B&> (p);
		std::cout << "Identified ref as B" << std::endl;
		(void)b;
	}
	catch (const std::bad_cast &e) {
	};
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "Identified ref as C" << std::endl;
		(void)c;
	}
	catch (const std::bad_cast &e) {
	};
	
}
int main()
{
	std::srand(std::time(0));

	Base* base = generate();
	identify(base);
	identify(*base);
	identify(nullptr);
	delete base;

	for (int i = 0; i < 9; i++)
	{
		Base *r;
		r = generate();
		identify(r);
		identify(*r);
		delete r;
	}
}