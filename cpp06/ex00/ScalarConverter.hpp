/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:12:30 by alli              #+#    #+#             */
/*   Updated: 2025/02/20 14:49:24 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& copy);
	public:
		static void convert(std::string str);
};

int	getType(std::string str);
void	convertChar(std::string str, char& c, int& i, float& f, double& d);
bool	convertFloat(std::string str, char& c, int& i, float& f, double& d);
bool	convertDouble(std::string str, char& c, int& i, float& f, double& d);
bool	convertInt(std::string str, char& c, int& i, float& f, double& d);
void	printScalarConverter(std:: string str, char& c, int& i, float& f, double& d);

bool	isInt(std::string str);
int		floatOrDouble(std::string str);
#endif