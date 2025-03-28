/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:57:35 by alli              #+#    #+#             */
/*   Updated: 2024/10/30 15:50:59 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	Fun("Fun");
	ClapTrap	Scary("Scary");
	ClapTrap	Unamused("Unamused");

	Fun.attack("Scary");
	Scary.takeDamage(5);
	Scary.beRepaired(3);

	Fun.attack("Scary");
	Scary.takeDamage(10);
	Scary.attack("Fun");

	for (int i = 0; i < 10; i++)
		Fun.attack("Unamused");
	return (0);
}

