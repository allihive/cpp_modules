/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:21:09 by alli              #+#    #+#             */
/*   Updated: 2024/11/19 12:12:43 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	createBureau()
{
	std::cout << "\n----------Create Bureau----------" << std::endl;
	try
	{
		Bureaucrat bebe("Bebe", 150);
		Bureaucrat baby("Baby", 40);
		Bureaucrat babe("Babe", 1);
		std::cout << "Bureau is created" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	faultyBureau()
{
	std::cout << "\n----------Faulty Bureau----------" << std::endl;
	try
	{
		Bureaucrat lowBebe("Low Bebe", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat highBaby("High Baby", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}
void	changeBureau()
{
	std::cout << "\n----------Change Bureau----------" << std::endl;
	try
	{
		Bureaucrat normalBae("normalBae", 35);
		normalBae.decreaseGrade();
		std::cout << normalBae;
		normalBae.increaseGrade();
		std::cout << normalBae << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat lowBae("lowBae", 150);
		lowBae.increaseGrade();
		lowBae.decreaseGrade();
		std::cout << lowBae;
		lowBae.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat highBae("highBae", 1);
		highBae.decreaseGrade();
		highBae.increaseGrade();
		std::cout << highBae;
		highBae.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

void	streamBureau()
{
	std::cout << "\n----------Stream Bureau----------" << std::endl;
	Bureaucrat babydoll("Babydoll", 34);
	std::cout << babydoll;
}

int main()
{
	createBureau();
	faultyBureau();
	changeBureau();
	streamBureau();
}