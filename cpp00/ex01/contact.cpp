/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:26:23 by alli              #+#    #+#             */
/*   Updated: 2024/10/17 14:42:20 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

Contact::~Contact() {}

std::string	Contact::getFirstName()
{	
	return(firstName);
}
std::string Contact::getLastName()
{
	return(lastName);
}

std::string Contact::getNickname()
{
	return (nickname);
}
std::string Contact::getPhoneNumber()
{
	return (phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return (darkestSecret);
}

void	Contact::setIndex(int i)
{
	this->index = i;
}

void	Contact::clearContact()
{
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
}

void Contact::showContact()
{
	std::cout << firstName << std::endl;
	std::cout << lastName << std::endl;
	std::cout << nickname << std::endl;
	std::cout << phoneNumber << std::endl;
	std::cout << darkestSecret << std::endl;
}

std::string readStr(std::string str)
{
	std::string	input;
	
	std::cout << str;
	std::getline(std::cin, input);
	while (1)
	 {
		if (std::cin.eof())
		{
			std::cout << "EOF signal received bye bye";
			exit (0);
		}
		else if (input == "")
		{
			std::cin.clear();
			std::cout << "Please enter your information" << std::endl;
			return ("");
		}
		if (std::cin.good() && !input.empty())
			break ;
	}
	return (input);
}

bool	Contact::addNewContact(int index)
{
	std::cout << "Your new contact is in index: " << index << std::endl;
	std::cout << "Please enter your information" << std::endl;
	
	while (firstName == "")
		firstName = readStr("First name: ");
	while (lastName == "")
		lastName = readStr("Last name: ");
	while (nickname == "")
		nickname = readStr("Nickname: ");
	while (phoneNumber == "")
		phoneNumber = readStr("Phone number: ");
	while (darkestSecret == "")
		darkestSecret = readStr("Darkest Secret: ");
	std::cout << "You have successfully added a contact!" << std::endl;
	return (true);
}
