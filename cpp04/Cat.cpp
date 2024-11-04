/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:23:48 by alli              #+#    #+#             */
/*   Updated: 2024/11/04 16:19:14 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;
	else
		this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << ""
}