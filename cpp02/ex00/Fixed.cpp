/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:23:36 by alli              #+#    #+#             */
/*   Updated: 2024/10/28 14:50:50 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () : _fixed(0) 
{
	std::cout << "Constructor called" << std::endl;
}

Fixed::~Fixed ()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) 
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignement called" << std::endl;
	if (this != &f)
	{
		this->_fixed = f.getRawBits();
	}
	return (*this)
}