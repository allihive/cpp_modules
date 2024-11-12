/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:56:22 by alli              #+#    #+#             */
/*   Updated: 2024/11/08 12:00:36 by alli             ###   ########.fr       */
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
	std::cout << "Animal copy assignment called." << std::endl;
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
	std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}