/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:20:18 by alli              #+#    #+#             */
/*   Updated: 2024/10/29 13:26:22 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = integer << this->_fractional;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	float rounded = roundf(num * (1 << this->_fractional));
	this->_fixed = static_cast<int>(rounded);
}


Fixed & Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &f)
	{
		this->_fixed = f.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->_fixed) / (1 << this->_fractional));
}

int Fixed::toInt( void ) const
{
	return ((this->_fixed >> this->_fractional));
}

std::ostream& operator <<(std::ostream& stream, const Fixed& f)
{
	stream << f.toFloat();
	return (stream);
}