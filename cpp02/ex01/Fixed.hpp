/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:20:20 by alli              #+#    #+#             */
/*   Updated: 2024/10/29 13:25:33 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int _fixed;
		static const int _fractional = 8;
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float num);
		~Fixed();
		
		Fixed(const Fixed &f); //copy constructor
		Fixed &operator = (const Fixed &f); 
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif