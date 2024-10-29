/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:29:13 by alli              #+#    #+#             */
/*   Updated: 2024/10/29 15:43:23 by alli             ###   ########.fr       */
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
		Fixed(const Fixed& f);
		
		Fixed &operator = (const Fixed& num); 
		
		/*overloading arithmetic operator*/
		Fixed	operator+(const Fixed& num);
		Fixed	operator-(const Fixed& num);
		Fixed	operator/(const Fixed& num);
		Fixed	operator*(const Fixed& num);

		/*overloading comparision operator*/
		bool	operator>(const Fixed& num);
		bool	operator<(const Fixed& num);
		bool	operator>=(const Fixed& num);
		bool	operator<=(const Fixed& num);
		bool	operator==(const Fixed& num);
		bool	operator!=(const Fixed& num);
		
		/*overloading increment*/
		Fixed	operator++(int); //post increment
		Fixed&	operator++(); //pre increment
		Fixed	operator--(int);
		Fixed&	operator--();
		
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		static			Fixed& min(Fixed& num1, Fixed& num2);
		static const	Fixed& min(const Fixed& num1, const Fixed& num2);
		static			Fixed& max(Fixed& num1, Fixed& num2);
		static const	Fixed& max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& num);

#endif

