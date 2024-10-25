/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:52:45 by alli              #+#    #+#             */
/*   Updated: 2024/10/23 13:12:28 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{
	private:
		std::string	name;
		Weapon&		weapon; //weapon reference
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();
	
};

#endif