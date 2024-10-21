/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:25:53 by alli              #+#    #+#             */
/*   Updated: 2024/10/21 10:54:24 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* newbie = newZombie("Dolly"); //created on heap
	newbie->announce();
	delete newbie;
	
	randomChump("Polly");
	return (0);
}