/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:54:18 by alli              #+#    #+#             */
/*   Updated: 2024/11/18 12:38:29 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137, "No target")
{
	std::cout << "Default Shrubbery Creation Form created.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", 147, 137, target)
{
	std::cout << "Shrubbery Creation Form created.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	std::cout << "Shrubbery Creation Form copy constructor called.\n";
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
		AForm::operator=(copy);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form deleted.\n";
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outfile;

	outfile.open(this->target + "_shrubbery");
	if (!outfile.is_open())
	{
		std::cerr << "Outfile was unable to be opened in Shrubbery Creation form.\n";
		return;
	}
	
	outfile << "    /\\        *    " << std::endl;
	outfile << "   //\\\\     ***   " << std::endl;
	outfile << "  /// \\\\   *****  " << std::endl;
	outfile << "    ||         |    " << std::endl;
}
