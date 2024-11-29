/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:38:04 by alli              #+#    #+#             */
/*   Updated: 2024/11/29 14:37:31 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main () {
	Data newStruct;
	
	newStruct.i = 5;
	newStruct.c = 'a';
	newStruct.d = 6.0;
	newStruct.f = 7.0f;
	
	std::cout << "-----Original-----" << std::endl;
	std::cout << "newStruct i: " << newStruct.i << std::endl;
	std::cout << "newStruct c: " << newStruct.c << std::endl;
	std::cout << "newStruct d: " << newStruct.d << std::endl;
	std::cout << "newStruct f: " << newStruct.f << std::endl;
	
	uintptr_t serializeIt = Serializer::serialize(&newStruct);
	std::cout << "-----Serialized-----" << std::endl;
	std::cout << "Serialized address: " << &serializeIt << std::endl;

	std::cout << "-----Deserialized-----" << std::endl;
	Data* deserializeIt = Serializer::deserialize(serializeIt);
	std::cout << deserializeIt->i << std::endl;
	std::cout << deserializeIt->c << std::endl;
	std::cout << deserializeIt->d << std::endl;
	std::cout << deserializeIt->f << std::endl;
	
}