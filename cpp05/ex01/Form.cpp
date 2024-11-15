/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:41:06 by alli              #+#    #+#             */
/*   Updated: 2024/11/15 11:58:48 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form () : _name("No name"), _isSigned(false), _gradeRequired(150), _gradeToExecute(3)
{
	std::cout << "Form constructor called.\n";
}

Form::Form(const std::string name, int gradeRequired, int gradeToExec) :
	_name(name), _gradeRequired(gradeRequired), _gradeToExecute(gradeToExec)
{
	if (this->_gradeRequired > 150)
		throw (GradeTooLowException("The grade required is too low"));
	if (this->_gradeRequired < 1)
		throw (GradeTooHighException("The grade required is too high"));
	if (this->_gradeToExecute > 150)
		throw (GradeTooLowException("The grade to execute is too low"));
	if (this->_gradeToExecute < 1)
		throw (GradeTooHighException("The grade to execute is too high"));
	std::cout << _name << " form is created with grade required: " << _gradeRequired << " and grade to execute: "
		<< _gradeToExecute << std::endl;
	
}
Form::Form(const Form& copy) :
 _name(copy._name), _isSigned(copy._isSigned), _gradeRequired(copy._gradeRequired), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << "Copy constructor called.\n";
}

Form::~Form()
{
	std::cout << "Form destructor called.\n";
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		_isSigned = copy._isSigned;
	return *this;
}

Form::GradeTooHighException::GradeTooHighException(const std::string& msg) : _msg(msg) {}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg) : _msg(msg) {}

const char* Form::GradeTooHighException::what() const noexcept 
{
	return _msg.c_str();
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return _msg.c_str();
}

/*Getters*/
const std::string& Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}

int	Form::getGradeRequired() const
{
	return (this->_gradeRequired);
}

int	Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeRequired)
	{
		this->_isSigned = true;
	}
	else
		throw GradeTooLowException("Your grade is too low. Not sorry");
}

std::ostream& operator<<(std::ostream& stream, const Form& formz)
{
	stream << formz.getName() << ", grade required: " << formz.getGradeRequired()
	<< ", grade to execute: " << formz.getGradeRequired() << " Signature status: " << formz.getIsSigned() << std::endl;
	return (stream);
}