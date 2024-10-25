/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:52:47 by alli              #+#    #+#             */
/*   Updated: 2024/10/23 13:07:22 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &setWeapon)
{
	this->weapon = &setWeapon;
}

void HumanB::attack()
{
	if (!weapon || weapon->getType().empty())
	{
		std::cout << this->name << " has no weapon" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with weapon " << this->weapon->getType() << std::endl;
}