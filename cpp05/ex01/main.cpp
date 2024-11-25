/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:21:09 by alli              #+#    #+#             */
/*   Updated: 2024/11/25 12:48:21 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	createForm()
{
	std::cout << "\n----------Create Form----------" << std::endl;
	try
	{
		Form adopt("Adopt", 20, 65);
		Form recycle("Recycle", 45, 56);
		
		Bureaucrat dede("Dede", 5);
		dede.signForm(adopt);

	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	faultyForm()
{
	try
	{
		std::cout << "\n----------Faulty Form----------" << std::endl;
		Form shop("Shop", 1, 9);
		Bureaucrat didi("Didi", 8);
		
		didi.signForm(shop);	
		shop.beSigned(didi);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	streamForm()
{
	std::cout << "\n----------Stream Form----------" << std::endl;
	Form acquire("Acquire", 35, 67);
	std::cout << acquire;
	Bureaucrat babydoll("Babydoll", 34);
	std::cout << babydoll;
}

int main()
{
	createForm();
	faultyForm();
	streamForm();
}