/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:09:28 by alli              #+#    #+#             */
/*   Updated: 2024/11/19 12:52:23 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern constructed.\n";
}

Intern::Intern(const Intern& copy)
{
	(void)copy;
	std::cout << "Copy constructor Intern called.\n";
}
Intern::~Intern()
{
	std::cout << "Intern destroyed.\n";
}

Intern& Intern::operator=(const Intern& copy)
{
	(void)copy;
	std::cout << "Copy assignment Intern called.\n";
	return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	AForm*		newForm;
	int			ind = 0;
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	for (unsigned long i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			ind = i;
			break;
		}
		ind++;
	}
	switch(ind) {
		case 0:
			newForm = new (std::nothrow) ShrubberyCreationForm(target);
			break;
		case 1:
			newForm = new (std::nothrow) RobotomyRequestForm(target);
			break;
		case 2:
			newForm = new (std::nothrow) PresidentialPardonForm(target);
			break;
		default:
			newForm = nullptr;
			std::cout << formName << " form does not exist and cannot be created." << std::endl;
			return newForm;
	}
	std::cout << "Intern creates " << formName << std::endl;
	return newForm;
}