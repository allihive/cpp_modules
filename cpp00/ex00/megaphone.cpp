/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:30:49 by alli              #+#    #+#             */
/*   Updated: 2024/10/14 14:37:01 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		for (unsigned long j = 0; j < str.length(); j++)
		{
			if (isupper(str[j]))
			{
				std::cout << toupper(str[j]);
			}
			else
				std::cout << str[j];
		}
	}
	std::cout << std::endl;
	return (0);
}