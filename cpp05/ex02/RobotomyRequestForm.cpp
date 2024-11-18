/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:55:10 by alli              #+#    #+#             */
/*   Updated: 2024/11/18 12:38:25 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request form", 72, 45, "No target")
{
	std::cout << "DefaultRobotomy Request Form constructed" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request form", 72, 45, target)
{
	std::cout << "Robotomy Request Form constructed" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
	std::cout << "Copy constructor for Robotomy Request Form called" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	std::cout << "Copy assignment for Robotomy Request Form called" << std::endl;
	if (this != &copy)
		AForm::operator=(copy);
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form constructed" << std::endl;
}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "Vrrrrrrr!" << std::endl;
	int randomRobot = rand() % 2;
	
	if (randomRobot == true)
		std::cout << this->target << " has been successfully robotomized." << std::endl;
	else
		std::cout << this->target << " robotomy has failed." << std::endl;
}
