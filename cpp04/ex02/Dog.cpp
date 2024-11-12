/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:25:12 by alli              #+#    #+#             */
/*   Updated: 2024/11/08 12:00:25 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Default Dog constructor called." << std::endl;
	brainz = new Brain();
	if (brainz == nullptr)
	{
		std::cout << "No brain for cat was allocated. \n";	
		return ;
	}
	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
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
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment called." << std::endl;
	if (this == &other)
		return (*this);
	else
	{
		Animal::operator=(other);
		*brainz = *other.brainz;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << type << " : WOOF WOOF" << std::endl;
}

Dog::~Dog()
{
	std::cout << type << " destroyed." << std::endl;
	delete brainz;
}

Brain *Dog::getBrain()
{
	return (brainz);
}