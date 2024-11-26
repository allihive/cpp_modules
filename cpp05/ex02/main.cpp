/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:21:09 by alli              #+#    #+#             */
/*   Updated: 2024/11/26 16:56:37 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		robots.execute(dede);
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
		Bureaucrat didi("Didi", 3);
		
		didi.signForm(shop);	
		shop.beSigned(didi);
		didi.executeForm(shop);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void	shrubberyFaultyForm()
{
	try
	{
		std::cout << "\n----------ShrubberyFaulty Form----------" << std::endl;
		ShrubberyCreationForm shrubz("Shrubz");
		Bureaucrat dada("Dada", 150);
		
		dada.signForm(shrubz);	
		shrubz.beSigned(dada);
		dada.executeForm(shrubz);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void	robotFaultyForm()
{
	try
	{
		std::cout << "\n----------Robot Faulty Form----------" << std::endl;
		RobotomyRequestForm roots("Root");
		Bureaucrat dodo("Dodo", 150);
		
		dodo.signForm(roots);	
		roots.beSigned(dodo);
		dodo.executeForm(roots);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}



int main()
{
	createForm();
	// presidentFaultyForm();
	// shrubberyFaultyForm();
	// robotFaultyForm();
	
}