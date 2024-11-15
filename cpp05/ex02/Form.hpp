/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:40:55 by alli              #+#    #+#             */
/*   Updated: 2024/11/15 10:22:56 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequired;
		const int			_gradeToExecute;
	public:
		Form();
		Form(const std::string _name, int gradeRequired, int gradeToExec);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		~Form();

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
		const std::string& getName() const;
		bool		getIsSigned() const;
		int			getGradeRequired() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif