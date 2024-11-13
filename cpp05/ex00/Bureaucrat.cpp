/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:21:45 by alli              #+#    #+#             */
/*   Updated: 2024/11/13 15:24:19 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*Orthodox Canonical*/

Bureaucrat::Bureaucrat() : _name("No Name"), _grade(150)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat is destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade > 150)
	{
		throw (GradeTooLowException("Initial grade is too low! Please put a grade between 1-150\n"));
	}
	if (grade < 1)
	{
		throw (GradeTooHighException("Initial grade is too high! Please put a grade between 1-150\n"));
	}
	_grade = grade;
	std::cout << _name << " is constructed with grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment called.\n";
	if (this != &other)
		_grade = other._grade;
	return *this;
}

/*getters*/

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

/*grade functions*/

void	Bureaucrat::increaseGrade()
{
	if (_grade == 1)
	{
		throw(GradeTooHighException("Grade is too high can no longer increment\n"));
	}
	this->_grade--;
}
void	Bureaucrat::decreaseGrade()
{
	if(_grade == 150)
	{
		throw(GradeTooLowException("Grade is too low can no longer decrease\n"));
	}
	this->_grade++;
}

/*Exception message functions*/

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) : _msg(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) : _msg(msg) {}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return _msg.c_str();
}
const char* Bureaucrat::GradeTooHighException::what() const noexcept 
{
	return _msg.c_str();
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bur)
{
	stream << bur.getName() << ", bureaucrat grade" << bur.getGrade() << "." << std::endl;
	return (stream);
}