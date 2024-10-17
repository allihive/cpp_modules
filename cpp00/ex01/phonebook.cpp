/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:50:02 by alli              #+#    #+#             */
/*   Updated: 2024/10/17 14:47:05 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : contactCount(0) {}

Phonebook::~Phonebook() {}

void	Phonebook::addContact()
{
	static int count;
	int	index = count % 8;
	contacts[index].setIndex(index);
	contacts[index].clearContact();
	if (contacts[index].addNewContact(index) == true)
	{
		contactCount++;
		count++;
	}
}

std::string	checklen(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Phonebook::createTable()
{
	std::cout << std::setw(10) << std::right << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
}

bool	Phonebook::displayContact()
{
	int numOfContacts = contactCount;

	if (numOfContacts == 0)
	{
		std::cout << "No contacts are in your phonebook :( please add some" << std::endl;
		return (false);	
	}
	if (contactCount > 0)
	{
		createTable();
		if (contactCount > 8)
			contactCount = 8;
		for (int i = 0; i < contactCount; i++)
		{
			std::cout << std::endl << std::right
					<< std::setw(10) << i << "|" 
					<< std::setw(10) << checklen(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << checklen(contacts[i].getLastName()) << "|"
					<< std::setw(10) << checklen(contacts[i].getNickname()) << std::endl;
		}
	}
	return (true);
}

void	Phonebook::searchIndex()
{
	std::string input;
	int	num;
	
	std::cout << "Please input the index to see the contact" << std::endl;
	std::getline(std::cin, input);
	while(1)
	{
		try {
		num = std::stoi(input);
		if (std::cin.eof())
		{
			std::cout << "EOF signal received in search index byyeeee" << std::endl;
			exit (0);
		}
		if (num >= 0 && num <= 7)
		{
			if (contactCount - 1 < num)
			{
				std::cout << "The index you put does not exist " << std::endl;
				break ;
			}
			else
			{
				contacts[num].showContact();
				break ;
			}
		}
		else if (num > 7 || num < 0)
		{
			std::cout << "Please input a valid index between 0 - 7" << std::endl;
			break ;
		}
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "Please input a valid argument" << std::endl;
			break ;
		}
	}
}