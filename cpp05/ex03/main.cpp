/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:21:09 by alli              #+#    #+#             */
/*   Updated: 2024/11/25 13:58:07 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	createForm()
{
	std::cout << "\n----------Create Form----------" << std::endl;
	try
	{
		PresidentialPardonForm president("President");
		RobotomyRequestForm robots("Robot");
		ShrubberyCreationForm shrubs("Shrubs");
		Bureaucrat dede("Dede", 4);
		
		dede.signForm(president);
		dede.signForm(robots);
		dede.signForm(shrubs);

		dede.executeForm(president);
		dede.executeForm(robots);
		dede.executeForm(shrubs);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	presidentFaultyForm()
{
	try
	{
		std::cout << "\n----------President Faulty Form----------" << std::endl;
		PresidentialPardonForm shop("Shop");
		Bureaucrat didi("Didi", 150);
		
		didi.signForm(shop);	
		shop.beSigned(didi);
		didi.executeForm(shop);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	internForm()
{
	std::cout << "\n----------Intern Creates Form----------" << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << std::endl;
	Intern wrongName;
	AForm *stuff;
	stuff = wrongName.makeForm("hello there", "friend");
	delete stuff;
	delete rrf;
}



int main()
{
	createForm();
	presidentFaultyForm();
	internForm();
}