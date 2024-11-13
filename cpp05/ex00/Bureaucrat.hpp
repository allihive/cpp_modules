/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:21:50 by alli              #+#    #+#             */
/*   Updated: 2024/11/13 15:17:54 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string const _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		
		const std::string& getName() const;
		int getGrade() const;
		void	increaseGrade();
		void	decreaseGrade();
		
		class GradeTooHighException : public std::exception
		{
			private:
				std::string _msg;
			public:
				virtual const char* what() const noexcept override;
				GradeTooHighException(const std::string& msg) : _msg(msg) {}
				virtual const char* what() const noexcept override;
		};
		
		class GradeTooLowException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooLowException(const std::string& msg) : _msg(msg) {}
				virtual const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif