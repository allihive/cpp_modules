/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:53:09 by alli              #+#    #+#             */
/*   Updated: 2024/10/21 14:27:54 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int zombieCount = 10;
	
	Zombie* newZomHor = zombieHorde(zombieCount, "Bob");
	for (int i = 0; i < zombieCount; i++)
	{
		std::cout << "Zombie " << i << ": " << std::flush;
		newZomHor[i].announce();
	}
	for (int i = zombieCount - 1; i >= 0; i--)
	{
		newZomHor[i].~Zombie();
	}
	delete[] newZomHor;
	return 0;
}