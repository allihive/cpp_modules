/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:57:35 by alli              #+#    #+#             */
/*   Updated: 2024/10/31 14:01:19 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap	Fun("Fun");
	ScavTrap	Scary("Scary");
	ScavTrap	Unamused("Unamused");

	Fun.attack("Scary");
	Scary.takeDamage(5);
	Scary.beRepaired(3);

	Fun.attack("Scary");
	Scary.takeDamage(10);
	Scary.attack("Fun");

	Unamused.guardGate();
	return (0);
}
