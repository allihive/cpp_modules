/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:24:13 by alli              #+#    #+#             */
/*   Updated: 2024/10/21 14:46:48 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie () {};

Zombie::~Zombie ()
{
	std::cout << "Zombie " << this->_name << " is dead." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
void	Zombie::announce()
{
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}