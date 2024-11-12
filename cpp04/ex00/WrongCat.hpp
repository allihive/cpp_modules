/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:21:57 by alli              #+#    #+#             */
/*   Updated: 2024/11/07 11:15:17 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public: 
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& copy);
		~WrongCat();

		void	makeSound() const;
};

#endif