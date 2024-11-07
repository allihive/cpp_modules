/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:44:42 by alli              #+#    #+#             */
/*   Updated: 2024/11/07 16:16:24 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}

Brain::~Brain()
{
	std::cout << "Brain is destroyed!" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain is being copy constructed." << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}
Brain& Brain::operator=(const Brain& copy)
{
	std::cout << "Brain copy assigned BOOM" << std::endl;
	if (this == &copy)
		return (*this);
	else
		for(int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	return (*this);
}

std::string Brain::getIdea(int index)
{
	// if (index >= 100 || index < 0)
	// {
	// 	return ("Not a valid index");
	// }
	// // else if (!ideas[index].empty())
	// return(this->ideas[index]);
	// // return ("Idea is not valid");
	std::cout << index <<std::endl;
	
	if (index < 0 || index >= 100)
		return ("Index is out of range(0-99)");
	std::cout << ideas[index] << std::endl;
	return (this->ideas[index]);
}

void Brain::setIdea(int i, std::string idea)
{
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
	else
		std::cout << "Error, must be from 0 to 99" << std::endl;
}