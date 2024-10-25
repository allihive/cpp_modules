/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:16:37 by alli              #+#    #+#             */
/*   Updated: 2024/10/24 10:38:13 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string fakeReplace(std::string buffer, size_t pos, std::string s1, std::string s2)
{
	buffer.erase(pos, s1.length());
	return (buffer.insert(pos, s2));
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Please put the appropriate amount of arguments <filename> (s1) (s2)" << std::endl;
		return (1);
	}
	char c;
	std::string buffer;
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream inFile(filename);
	std::ofstream outFile(filename + ".replace");

	if (!inFile.is_open() || !outFile.is_open())
	{
		std::cout << "Error reading file" << std::endl;
		return 1;
	}
	if (inFile.eof() || s1.empty() || s2.empty())
	{
		std::cout << "Something is empty" << std::endl;
		return 1;
	}
	while (inFile >> std::noskipws >> c)
	{
		buffer += c;
	}
	size_t pos = 0;
	while ((pos = buffer.find(s1, pos)) != std::string::npos)
	{
		buffer = fakeReplace(buffer, pos, s1, s2);
		pos += s2.length();
	}
	outFile << buffer;
	inFile.close();
	outFile.close();
}
