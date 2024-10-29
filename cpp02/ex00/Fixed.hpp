/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:23:33 by alli              #+#    #+#             */
/*   Updated: 2024/10/28 10:48:08 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_fixed;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed &f); //copy constructor
		Fixed &operator = (const Fixed &f); //assignment operator
		int		getRawBits() const;
		void	setRawBits(int const raw);
};


#endif