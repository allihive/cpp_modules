/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:56:20 by alli              #+#    #+#             */
/*   Updated: 2024/11/01 13:20:07 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& other);
		~Animal();
		
		Animal& operator=(const Animal& other);
};

class Dog : public Animal{
	protected:
		std::string type;
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();
		
		Dog& operator=(const Dog& other);
		void	makeSound(){
			std::cout << "The dog says: woof woof" << std::endl;
		}
};

class Cat : public Animal{
	protected:
		std::string type;
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();
		
		Cat& operator=(const Cat& other);
		void	makeSound(){
			std::cout << "The cat says: meow meow" << std::endl;
		}
};

#endif