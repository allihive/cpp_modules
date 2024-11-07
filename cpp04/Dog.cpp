/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:25:12 by alli              #+#    #+#             */
/*   Updated: 2024/11/06 16:16:48 by alli             ###   ########.fr       */
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