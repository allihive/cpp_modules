/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:41:06 by alli              #+#    #+#             */
/*   Updated: 2024/11/18 11:16:39 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm () : _name("No name"), _isSigned(false), _gradeRequired(150), _gradeToExecute(3)
{
	std::cout << "AForm constructor called.\n";
}

AForm::AForm(const std::string name, int gradeRequired, int gradeToExec, const std::string target) :
	_name(name), _gradeRequired(gradeRequired), _gradeToExecute(gradeToExec), _target(target)
{
	if (this->_gradeRequired > 150)
		throw (GradeTooLowException("The grade required is too low"));
	if (this->_gradeRequired < 1)
		throw (GradeTooHighException("The grade required is too high"));
	if (this->_gradeToExecute > 150)
		throw (GradeTooLowException("The grade to execute is too low"));
	if (this->_gradeToExecute < 1)
		throw (GradeTooHighException("The grade to execute is too high"));
	std::cout << _name << " AForm is created with grade required: " << _gradeRequired << " and grade to execute: "
		<< _gradeToExecute << std::endl;
	
}
AForm::AForm(const AForm& copy) :
 _name(copy._name), _isSigned(copy._isSigned), _gradeRequired(copy._gradeRequired), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << "Copy constructor called.\n";
}

AForm::~AForm()
{
	std::cout << "AForm destructor called.\n";
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
		_isSigned = copy._isSigned;
	return *this;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg) : _msg(msg) {}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg) : _msg(msg) {}

AForm::FormNotSigned::FormNotSigned(const std::string& msg) : _msg(msg) {}

const char* AForm::GradeTooHighException::what() const noexcept 
{
	return _msg.c_str();
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return _msg.c_str();
}

const char* AForm::FormNotSigned::what() const noexcept
{
	return _msg.c_str();
}

/*Getters*/
const std::string& AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int	AForm::getGradeRequired() const
{
	return (this->_gradeRequired);
}

int	AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeRequired)
	{
		this->_isSigned = true;
	}
	else
		throw GradeTooLowException("Your grade is too low. Not sorry");
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->_isSigned == false)
		throw (FormNotSigned("Form is not signed."));
	else if (executor.getGrade() > this->_gradeToExecute)
		throw (GradeTooLowException("Executor's grade is too low"));
	else
		this->executeAction();
}

std::ostream& operator<<(std::ostream& stream, const AForm& formz)
{
	stream << formz.getName() << ", grade required: " << formz.getGradeRequired()
	<< ", grade to execute: " << formz.getGradeRequired() << " Signature status: " << formz.getIsSigned() << std::endl;
	return (stream);
}