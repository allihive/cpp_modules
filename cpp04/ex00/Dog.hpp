/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:25:18 by alli              #+#    #+#             */
/*   Updated: 2024/11/07 14:39:21 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *Brain;
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();
		
		Dog& operator=(const Dog& other);
		void	makeSound() const override;
		Brain* getBrain();
};

#endif