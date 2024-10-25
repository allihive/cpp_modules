/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:25:19 by alli              #+#    #+#             */
/*   Updated: 2024/10/24 14:47:48 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string line;

	std::cout << "Please write level: DEBUG or INFO or WARNING or ERROR" << std::endl;
	while (1)
	{
		getline(std::cin, line);
		if (line.empty())
		{
			std::cout << "Empty input try again" << std::endl;
			break;
		}
		else if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl;
		}
		else
		{
			harl.complain(line);
			if (findLevel(line) != -1)
				break;
		}
	}
}