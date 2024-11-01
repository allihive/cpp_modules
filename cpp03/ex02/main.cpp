/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:57:35 by alli              #+#    #+#             */
/*   Updated: 2024/11/01 10:28:17 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

void	Claps()
{
	std::cout << "ClapTrap in the house.\n";
	ClapTrap Clap("Clapping");

	Clap.attack("Slap");
	Clap.takeDamage(6);
	Clap.beRepaired(9);
}

void	Scav()
{
	std::cout << "ScavTrap in the house.\n";
	ScavTrap Savage("Savage");

	Savage.attack("Package");
	Savage.guardGate();
}

void	Frag()
{
	std::cout << "FragTrap in the house.\n";
	FragTrap Fragment("Fragment");

	Fragment.attack("Attachment");
	Fragment.highFivesGuys();
}

int main()
{
	Claps();
	std::cout << std::endl;
	Scav();
	std::cout << std::endl;
	Frag();
	std::cout << std::endl;
	
	return (0);
}
