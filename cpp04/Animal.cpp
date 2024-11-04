/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:56:22 by alli              #+#    #+#             */
/*   Updated: 2024/11/04 15:22:50 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "default animal";
	std::cout << "Default Animal constructor" << std::endl;
}
Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal type constructed" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = other;
}
Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
		return *this;
	else
		this->type = other.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << type << " animal does not make a sound!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default Animal destructor" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}