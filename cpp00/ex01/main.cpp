/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:59:44 by alli              #+#    #+#             */
/*   Updated: 2024/10/18 12:18:40 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

void	exit_message()
{
	if (std::cin.eof())
		std::cout << "EOF signal received. " << std::endl;
	else
		std::cout << "Error reading input. " << std::endl;
	exit (1);
}

int main(int argc, char **argv)
{
	std::string	cmd;
	Phonebook	phonebook;
	
	(void)argv;
	if (argc != 1)
		std::cout << "Invalid amount of arguments";
	while (1)
	{
		std::cout << "Please write a command: ADD, SEARCH, or EXIT > " << std::endl;
		if (!(std::getline(std::cin, cmd)))
			exit_message();
		else if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
		{
			if (phonebook.displayContact() == false)
				continue ;
			else 
				phonebook.searchIndex();
		}
		else if (cmd == "EXIT")
		{
			std::cout << "Thank you for using my Awesome Phonebook! Bye!";
			break ;
		}
		else
			std::cout << "Please input a valid argument"<< std::endl;
	}
	return (0);
}
