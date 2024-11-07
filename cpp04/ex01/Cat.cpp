/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:23:48 by alli              #+#    #+#             */
/*   Updated: 2024/11/07 16:17:14 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << type << " copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment called." << std::endl;
	if (this == &other)
		return *this;
	else
		this->type = other.type;
	return *this;
}

void Cat::makeSound() const 
{
	std::cout << type << " : meooooowwwww!" << std::endl;
}

Cat::~Cat()
{
	std::cout << type <<" destroyed." << std::endl;
}

Brain* Cat::getBrain()
{
	return (this->Brain);
}