/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:12:32 by alli              #+#    #+#             */
/*   Updated: 2024/11/25 15:00:35 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar()
{
	std::cout << "Default constructor called.\n" ;
}

Scalar::Scalar(const Scalar& copy) : Scalar(copy)
{
	std::cout << "Copy constructor called.\n";
}
Scalar& Scalar::operator=(const Scalar& copy)
{
	(void)copy;
	std::cout << "Copy asignment called.\n";
	return *this;
}

Scalar::~Scalar()
{
	std::cout << "Destructor called.\n";
}
void	Scalar::convert(std::string str)
{
	int type = 0;
	type = getType(str);
	
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	
	switch (type)
	{
		case 0:
			convertChar(str, c, i, f, d);
			break;
		case 1:
			convertFloat(str, c, i, f, d);
			break;
		case 2:
			convertDouble(str, c, i, f, d);
			break;
		case 3:
			convertInt(str, c, i, f, d);
			break;
	default:
		std::cout << "impossible" << std::endl;
	}
	printScalar(str, c, i , f, d);
}