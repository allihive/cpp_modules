/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:25:19 by alli              #+#    #+#             */
/*   Updated: 2024/10/24 15:55:35 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string line;
	
	if (argc != 2)
	{
		std::cout << "Please write level: DEBUG or INFO or WARNING or ERROR" << std::endl;
		return (1);
	}
	line = argv[1];
	if (line.empty())
	{
		std::cout << "Empty input try again" << std::endl;
		return (1);
	}
	else
	{
		harl.complain(line);
		return (0);
	}
}