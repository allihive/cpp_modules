/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarHelpers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:12:27 by alli              #+#    #+#             */
/*   Updated: 2024/11/26 15:15:18 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

bool isInt(std::string str)
{
	int i = 0;
	while (str.length() && (str[i] != '\0'))
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}
int infNancheck(std::string str)
{
	if (str == "+inf" || str == "-inf" || str == "nan")
		return 4;
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return 3;
	return 0;
}

int floatOrDouble(std::string str)
{
	unsigned long i = 0;
	int count = 0;
	int flag = 0;
	
	if (infNancheck(str) > 2)
		return (infNancheck(str));
	while (i < str.length() - 1)
	{
		if (i == 0 && str[0] == '-')
			i++;
		while (isdigit(str[i]) && str[i] != '-')
			i++;
		if (str[i] == '.' && isdigit(str[i + 1]))
		{
			count++;
			i++;
			flag = 1;
			continue;
		}
		else if ((!isdigit(str[i]) && str[str.length() - 1] != 'f') || str[i] == '-')
			return 0;
		i++;
	}
	if (count > 1)
		return 0;
	if (str[(str.length() - 1)] == 'f' && flag == 1)
		return 3; //float
	if (flag == 1)
		return 4; // double
	return 0;
}

int	getType(std::string str)
{
	int len = str.length();
	
	
	if (str[0] >= 'a' && str[0] <= 'z' && len == 1)
		return (1);
	if (isInt(str) == true)
		return (2);
	if (floatOrDouble(str) == 3)
		return 3;
	if (floatOrDouble(str) == 4)
		return 4;
	return (0);
}

void	convertChar(std::string str, char& c, int& i, float& f, double& d)
{
	c = str[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
}

bool convertFloat(std::string str, char& c, int& i, float& f, double& d)
{
	try
	{
		f = std::stof(str);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		c = static_cast<char>(f);
	}
	catch (std::exception &e)
	{
		std::cerr << "Unable to convert to float" << std::endl;
		return false;
	}
	return true;
}

bool convertDouble(std::string str, char& c, int& i, float& f, double& d)
{
	try
	{
		d = std::stod(str);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		c = static_cast<char>(d);
	}
	catch (std::exception &e)
	{
		std::cerr << "Unable to convert to double" << std::endl;
		return false;
	}
	return true;
}
bool convertInt(std::string str, char& c, int& i, float& f, double& d)
{
	try
	{
		i = std::stoi(str);
		f = static_cast<float>(i);
		c = static_cast<char>(i);
		d = static_cast<double>(d);
	}
	catch (std::exception &e)
	{
		std::cerr << "Unable to convert to int" << std::endl;
		return false;
	}
	return true;
}
void printScalar(std::string str, char& c, int& i, float& f, double& d)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}