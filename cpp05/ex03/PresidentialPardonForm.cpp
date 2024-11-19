/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:55:04 by alli              #+#    #+#             */
/*   Updated: 2024/11/19 09:46:29 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Presidential Pardon Form", 25, 5, "No name")
{
	std::cout << "Default Presidential Pardon Form created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("Presidential Pardon Form", 25, 5, target)
{
	std::cout << "Constructor Presidential Pardon Form called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form deleted." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	std::cout << "Copy constructor for Presidential Pardon Form called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
		AForm::operator=(copy);
	return *this;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}