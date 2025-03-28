/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:23:36 by alli              #+#    #+#             */
/*   Updated: 2024/10/29 09:18:55 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () : _fixed(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed ()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed & Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignement called" << std::endl;
	if (this != &f)
	{
		this->_fixed = f.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;
	return (this->_fixed);
}

void Fixed::setRawBits (int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	this->_fixed = raw;
}