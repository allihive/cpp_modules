/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:25:12 by alli              #+#    #+#             */
/*   Updated: 2024/11/07 15:03:30 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << type << " copy constructor" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment called." << std::endl;
	if (this == &other)
		return (*this);
	else
		type = other.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << type << " : WOOF WOOF" << std::endl;
}

Dog::~Dog()
{
	std::cout << type << " destroyed." << std::endl;
}