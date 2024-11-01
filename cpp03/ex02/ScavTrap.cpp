/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:58:56 by alli              #+#    #+#             */
/*   Updated: 2024/10/31 14:01:59 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default constructor called for ScavTrap.\n";
}

ScavTrap::ScavTrap(const std::string _name) : ClapTrap(_name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor is called.\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor is called.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor is called. \n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment called.\n";
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << _name << " is Hodor guarding the gate!!\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is dead.\n";
		return ;
	}
	if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " has no energy points left to attack.\n";
	else
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks "
			<< target << ", causing " << _attackDamage << " points of damage!\n";
	}
}

