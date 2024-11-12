/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:25:18 by alli              #+#    #+#             */
/*   Updated: 2024/11/08 11:48:13 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();
		
		Dog& operator=(const Dog& other);
		void	makeSound() const override;
		Brain* getBrain();
	private:
		Brain* brainz;
};

#endif