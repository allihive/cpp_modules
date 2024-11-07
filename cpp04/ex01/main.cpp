/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:55:07 by alli              #+#    #+#             */
/*   Updated: 2024/11/07 16:15:32 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


// static void	testDeepCopies()
// {
// 	std::cout << "\033[36m" << "\n---Original cat---\n" << "\033[0m";
// 	Cat	catOriginal;
// 	catOriginal.getBrain()->setIdea(0, "Experts suggest investing in premium wet food");
// 	catOriginal.getBrain()->setIdea(1, "Veterinarians endorse a steady supply of laser pointers");
// 	catOriginal.getBrain()->setIdea(2, "Analysts highlight the benefits of catnip investments");
// 	std::cout << "\033[5;93m" << "\n---Original ideas---\n" << "\033[0m";
// 	catOriginal.getBrain()->getIdea(0);

// 	std::cout << "\033[36m" << "\n---Copy constructor---\n" << "\033[0m";
// 	Cat	catCopy1(catOriginal);
// 	std::cout << "\033[5;93m" << "\n---Copied ideas---\n" << "\033[0m";
// 	catCopy1.getBrain()->getIdea(1);

// 	std::cout << "\033[36m" << "\n---Copy assignment operator---\n" << "\033[0m";
// 	Cat	catCopy2;
// 	catCopy2 = catOriginal;
// 	std::cout << "\033[5;93m" << "\n---Copied ideas---\n" << "\033[0m";
// 	catCopy2.getBrain()->getIdea(2);

// 	std::cout << "\033[36m" << "\n---Destructing objs---\n" << "\033[0m";
// }
// static void AnimalArray()
// {
// 	const int Count = 6;
// 	const Animal* Animals[Count];

// 	std::cout << "------Creating animals-------" << std::endl;
// 	for (int i = 0; i < Count/2; i++)
// 		Animals[i] = new Dog();
// 	for (int i = Count/2; i < Count; i++)
// 		Animals[i] = new Cat();
// 	for (int i = 0; i < Count; i++)
// 		Animals[i]->makeSound();
	
// 	std::cout << "------Destroying animals-------" << std::endl;
// 	for (int i = 0; i < Count; i++)
// 		delete Animals[i];
// }

// int main()
// {	
// 	std::cout << "-------------------Test from Subjects-----------------"  << std::endl;
// 		const Animal* j = new Dog();
// 		const Animal* i = new Cat();
// 		delete j;//should not create a leak
// 		delete i;
// 	std::cout << "-------------------Animal Array-----------------" << std::endl;
// 	AnimalArray();
	
// 	std::cout << "-------------------Deep Copies-----------------" << std::endl;
	

// 	return 0;
// }

void deepCopyCat() {
	std::cout << "\n***deepCopyCat***\n";
	Cat catOriginal;
	// std::cout << "catOriginal address: " << catOriginal.getBrain() << std::endl;

	catOriginal.getBrain()->setIdea(0, "Sleep on the counch");
	catOriginal.getBrain()->setIdea(1, "Walk around a yard");

	std::cout << "idea: " << catOriginal.getBrain()->getIdea(0) << std::endl;
	std::cout << "idea: " << catOriginal.getBrain()->getIdea(1) << std::endl;

	// Cat copyCat = catOriginal;
	// std::cout << "copyCat address: " << copyCat.getBrain() << std::endl;

	// std::cout << "copied idea: " << copyCat.getBrain()->getIdea(99) << std::endl;
	// std::cout << "copied idea: " << copyCat.getBrain()->getIdea(1) << std::endl;

	// // modified origina data
	// catOriginal.getBrain()->setIdea(0, "Ohhhhhhhhhhhhhhhhh");

    // std::cout << "Modified original idea: " << catOriginal.getBrain()->getIdea(0) << std::endl;
    // std::cout << "Copy idea after modifying original: " << copyCat.getBrain()->getIdea(0) << std::endl;

	// std::cout << "--------------------" << std::endl;
	// std::cout << std::endl;
}

void deepCopyDog() {
	std::cout << "\n***deepCopyDog***\n";
	Dog dogOriginal;
	std::cout << "dogOriginal address: " << dogOriginal.getBrain() << std::endl;

	// dogOriginal.getBrain()->setIdea(0, "Play with owner");
	// dogOriginal.getBrain()->setIdea(1, "Eat ham");
	// dogOriginal.getBrain()->setIdea(2, "sleep in a bed");
	// // test for index that is out of range
	// dogOriginal.getBrain()->setIdea(100, "bark at neighbors");

	// std::cout << "idea: " << dogOriginal.getBrain()->getIdea(0) << std::endl;
	// std::cout << "idea: " << dogOriginal.getBrain()->getIdea(1) << std::endl;
	// std::cout << "idea: " << dogOriginal.getBrain()->getIdea(2) << std::endl;


	// Dog copyDog = dogOriginal;
	// std::cout << "copyDog address: " << copyDog.getBrain() << std::endl;

	// std::cout << "copied idea: " << copyDog.getBrain()->getIdea(0) << std::endl;
	// std::cout << "copied idea: " << copyDog.getBrain()->getIdea(1) << std::endl;
	// std::cout << "copied idea: " << copyDog.getBrain()->getIdea(2) << std::endl;

	// // modified origina data
    // dogOriginal.getBrain()->setIdea(0, "Aaaaaaaaaaaaaaaaa");

    // std::cout << "Modified original idea: " << dogOriginal.getBrain()->getIdea(0) << std::endl;
    // std::cout << "Copy idea after modifying original: " << copyDog.getBrain()->getIdea(0) << std::endl;

	// std::cout << "--------------------" << std::endl;
	// std::cout << std::endl;
}


int main() {

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;

	deepCopyCat();
	deepCopyDog();

	return (0);
}