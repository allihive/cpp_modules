/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:38:05 by alli              #+#    #+#             */
/*   Updated: 2024/10/21 10:04:22 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private: 
	std::string name;
	
	public:
	Zombie(std::string name);
	~Zombie();
	
	void	announce(void);
	void	setName(std::string name);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif