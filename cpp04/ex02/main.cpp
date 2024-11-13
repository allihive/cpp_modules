/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:55:07 by alli              #+#    #+#             */
/*   Updated: 2024/11/12 15:42:35 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


void	deepCopies()
{
	std::cout << "\n------Deep Copy Cat-------" << std::endl;
	Cat catOG;
	catOG.getBrain()->setIdea(0, "I'm the OG gangster cat.");
	catOG.getBrain()->setIdea(1, "Nobody can copy me!");
	catOG.getBrain()->setIdea(2, "Try to copy me and see what happens.");

	std::cout << "OG cat: " << catOG.getBrain()->getIdea(0) << std::endl;
	std::cout << "OG cat: " << catOG.getBrain()->getIdea(1) << std::endl;
	std::cout << "OG cat: " << catOG.getBrain()->getIdea(2) << std::endl;

	std::cout << "\n----copyCat----\n";
	Cat copyCat = catOG;
	std::cout << "Copy cat: " << copyCat.getBrain()->getIdea(1) << std::endl;
	
	Cat copyCat2(catOG);
	std::cout << "Copy cat: " << copyCat.getBrain()->getIdea(2) << std::endl;
	
	catOG.getBrain()->setIdea(0, "Deep copies are dangerous.");
	std::cout << "OG cat's modified idea: " << catOG.getBrain()->getIdea(0) << std::endl;
	copyCat.getBrain()->setIdea(1, "Better be careful OG");
	std::cout << "Copy cat's modified idea: " << copyCat.getBrain()->getIdea(1) << std::endl;
	

	std::cout << "\n------Deep Copy Dog-------" << std::endl;
	Dog dogOG;
	dogOG.getBrain()->setIdea(0, "I'm the OG gangster dog.");
	dogOG.getBrain()->setIdea(1, "Nobody can copy me!");
	dogOG.getBrain()->setIdea(2, "Try to copy me and see what happens.");

	std::cout << "OG dog: " << dogOG.getBrain()->getIdea(0) << std::endl;
	std::cout << "OG dog: " << dogOG.getBrain()->getIdea(1) << std::endl;
	std::cout << "OG dog: " << dogOG.getBrain()->getIdea(2) << std::endl;

	std::cout << "\n----copydog----\n";
	Dog copyDog = dogOG;
	std::cout << "Copy dog: " << copyDog.getBrain()->getIdea(1) << std::endl;
	
	Dog copyDog2(dogOG);
	std::cout << "Copy dog: " << copyDog.getBrain()->getIdea(2) << std::endl;
	
	dogOG.getBrain()->setIdea(0, "Deep copies are dangerous.");
	std::cout << "OG dog's modified idea: " << dogOG.getBrain()->getIdea(0) << std::endl;
	copyDog.getBrain()->setIdea(1, "Better be careful OG");
	std::cout << "Copy dog's modified idea: " << copyDog.getBrain()->getIdea(1) << std::endl;

	std::cout << "\n-------------------Destroy Deep Copies-----------------" << std::endl;
}
static void AnimalArray()
{
	const int Count = 6;
	const Animal* Animals[Count];

	std::cout << "------Creating animals-------" << std::endl;
	for (int i = 0; i < Count/2; i++)
		Animals[i] = new Dog();
	for (int i = Count/2; i < Count; i++)
		Animals[i] = new Cat();
	for (int i = 0; i < Count; i++)
		Animals[i]->makeSound();
	
	std::cout << "------Destroying animals-------" << std::endl;
	for (int i = 0; i < Count; i++)
		delete Animals[i];
}

int main()
{	
	std::cout << "-------------------Test from Subjects-----------------\n"  << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	std::cout << "\n-------------------Animal Array-----------------\n" << std::endl;
	AnimalArray();
	
	std::cout << "\n-------------------Deep Copies-----------------" << std::endl;
	deepCopies();

	return 0;
}
