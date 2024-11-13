/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:23:48 by alli              #+#    #+#             */
/*   Updated: 2024/11/12 15:47:17 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Default Cat constructor called." << std::endl;
	brainz = new Brain();
	if (brainz == nullptr)
	{
		std::cout << "No brain for cat was allocated. \n";	
		return ;
	}
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << type << " copy constructor" << std::endl;
	brainz = new Brain();
	if (brainz == nullptr)
	{
		std::cout << "No brain for cat was allocated. \n";
		return ;
	}
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment called." << std::endl;
	if (this == &other)
		return *this;
	else
	{
		Animal::operator=(other);
		*brainz = *other.brainz;
	}
	return *this;
}

void Cat::makeSound() const 
{
	std::cout << type << " : meooooowwwww!" << std::endl;
}

Cat::~Cat()
{
	std::cout << type << " destroyed." << std::endl;
	delete brainz;
}

Brain* Cat::getBrain()
{
	return (brainz);
}