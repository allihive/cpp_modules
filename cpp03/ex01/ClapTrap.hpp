/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:57:39 by alli              #+#    #+#             */
/*   Updated: 2024/10/31 13:52:05 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAPP_HPP
#define CLAPTRAPP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap& other);
		
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif