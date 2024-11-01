/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:57:41 by alli              #+#    #+#             */
/*   Updated: 2024/10/31 13:50:05 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("No name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor is initialized." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment called." << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead.\n";
		return ;
	}
	if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has no energy points left to attack.\n";
	else
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks "
			<< target << ", causing " << _attackDamage << " points of damage!\n";
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points and has died.\n";
		return ;
	}
	unsigned int damageTaken = 0;
	if (_hitPoints >= amount)
	{
		damageTaken += amount;
		std::cout << "ClapTrap " << _name << " has taken " << damageTaken << " points of damage. \n";
	}
	else
		_hitPoints = damageTaken;
	_hitPoints -= damageTaken;
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has taken too much damage and has died.\n";
	}
	
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead and cannot be revived.\n";
		return ;
	}
	if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has no energy points left to repair.\n";
	else
	{
		_energyPoints -= 1;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " has been repaired! " << _name << " now has "
					<< amount << " of hit points back and has a total of " << _hitPoints << " hit points\n";
	}
}