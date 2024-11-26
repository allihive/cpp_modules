/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:40:55 by alli              #+#    #+#             */
/*   Updated: 2024/11/26 16:36:57 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequired;
		const int			_gradeToExecute;
		const std::string	_target;
	public:
		AForm();
		AForm(const std::string _name, int gradeRequired, int gradeToExec, const std::string target);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		virtual ~AForm();

		class GradeTooHighException : public std::exception {
			private:
				std::string _msg;
			public:
				virtual const char* what() const noexcept override;
				GradeTooHighException(const std::string& msg);
		};
		class GradeTooLowException : public std::exception {
			private:
				std::string _msg;
			public:
				virtual const char* what() const noexcept override;
				GradeTooLowException(const std::string& msg);
		};
		class FormNotSigned : public std::exception {
			private:
				std::string _msg;
			public:
				virtual const char* what() const noexcept override;
				FormNotSigned(const std::string& msg);
		};
		
		const std::string& getName() const;
		bool		getIsSigned() const;
		int			getGradeRequired() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat& bureaucrat);
		const std::string	getTarget() const;
		void		execute(Bureaucrat const & executor) const;
		virtual void	executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif