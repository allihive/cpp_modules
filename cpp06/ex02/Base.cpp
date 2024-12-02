/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:57:37 by alli              #+#    #+#             */
/*   Updated: 2024/12/02 15:30:35 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	Base* base;
	srand(time(0));
	int random = rand() % 3;
	
	switch (random)
	{
		case 0:
			base = new(std::nothrow) A();
			return base;
		case 1:
			base = new(std::nothrow) B();
			return base;
		case 2:
			base = new(std::nothrow) C();
			return base;
		default:
			base = nullptr;
			return base;
	}
}

void identify(Base* p)
{
	if (A* a = dynamic_cast<A*> (p))
		std::cout << "Identified as A" << std::endl;
	else if (B* b = dynamic_cast<B*> (p))
		std::cout << "Identified as B" << std::endl;
	else if (C* c = dynamic_cast<C*> (p))
		std::cout << "Identified as C" << std::endl;
	else
		std::cout << "Is not identifiable" << std::endl;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&> (p);
		std::cout << "Identified as A" << std::endl;
	}
	catch (const std::bad_cast &e) {
	};
	try {
		B& b = dynamic_cast<B&> (p);
		std::cout << "Identified as B" << std::endl;
	}
	catch (const std::bad_cast &e) {
	};
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "Identified as C" << std::endl;
	}
	catch (const std::bad_cast &e) {
	};
	
}