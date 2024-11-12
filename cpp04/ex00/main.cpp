/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:55:07 by alli              #+#    #+#             */
/*   Updated: 2024/11/07 11:55:23 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	
	const Animal* meta = new Animal();
	meta->makeSound();
	delete meta;
	std::cout << "----------------------------------------------" << std::endl;
	
	const Animal* rufus = new Dog();
	std::cout << "Rufus is " << rufus->getType() << " type" << std::endl;
	rufus->makeSound(); 
	delete rufus;
	std::cout << "----------------------------------------------" << std::endl;
	
	const Animal* dolly = new Cat();
	std::cout << "Dolly is " << dolly->getType() << " type" << std::endl;
	dolly->makeSound();
	delete dolly;
	std::cout << "----------------------------------------------" << std::endl;

	const WrongAnimal* sheep = new WrongAnimal();
	sheep->makeSound();
	delete sheep;
	std::cout << "----------------------------------------------" << std::endl;

	const WrongCat* elephant = new WrongCat();
	elephant->makeSound();
	delete elephant;
	std::cout << "----------------------------------------------" << std::endl;
	

return 0;
}