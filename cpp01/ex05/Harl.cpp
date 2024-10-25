/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:25:24 by alli              #+#    #+#             */
/*   Updated: 2024/10/24 14:25:05 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout <<  "I like cheese." << std::endl;
}

void Harl::info()
{
	std::cout << "I like cheddar cheese." << std::endl;
}

void Harl::warning()
{
	std::cout << "I can only have cheddar cheese aged 10 years or more." << std::endl;
}

void Harl::error()
{
	std::cout << "How dare you give me cheddar aged for only 5 years and from a spotted cow?" << std::endl;
}

int findLevel(std::string line)
{
	std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4)
	{
		if (line == level[i])
			return i;
		i++;
	}
	return -1;
}


void Harl::complain(std::string level)
{
	void (Harl::*c_func[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	if (level.empty())
	{
		std::cout << "Harl level is empty" << std::endl;
		return ;
	}
	int lvlnum = findLevel(level);
	if (lvlnum > 4 || lvlnum < 0)
	{
		std::cout << "Invalid level, please put the correct level" << std::endl;
		return;
	}
	else
		(this->*c_func[lvlnum])();

}
