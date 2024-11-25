/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:12:30 by alli              #+#    #+#             */
/*   Updated: 2024/11/25 15:02:31 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <limits>

class Scalar {
	private:
		Scalar();
		Scalar(const Scalar&);
		~Scalar();
		Scalar& operator=(const Scalar& copy);
	public:
		static void convert(std::string str);
};

int	getType(std::string str);
void	convertChar(std::string str, char& c, int& i, float& f, double& d);
void	convertFloat(std::string str, char& c, int& i, float& f, double& d);
void	convertDouble(std::string str, char& c, int& i, float& f, double& d);
void	convertInt(std::string str, char& c, int& i, float& f, double& d);
void	printScalar(std:: string str, char& c, int& i, float& f, double& d);

#endif