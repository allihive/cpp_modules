/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:27:48 by alli              #+#    #+#             */
/*   Updated: 2024/11/01 12:30:51 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default constructor called for FragTrap.\n";
}

FragTrap::FragTrap(const std::string _name) : ClapTrap(_name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructor is called.\n";
}

FragTrap::FragTrap(const FragTrap& other)
{
	*this = other;
	std::cout << "FragTrap copy constructor is called.\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor is called. \n";
}

FragTrap &FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment called.\n";
	if (this == &other)
		return *this;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

void	FragTrap::highFivesGuys()
{
	std::cout << _name << " Giving the best high five!\n";
}