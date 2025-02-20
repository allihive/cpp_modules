/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:38:04 by alli              #+#    #+#             */
/*   Updated: 2025/02/20 11:26:32 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main () {
	Data data;
	
	data.i = 666;
	data.c = 'a';
	data.f = 4.0f;
	data.d = 6.0;

	std::cout << "-----Original-----" << std::endl;
	std::cout << "data i: " << data.i << std::endl;
	std::cout << "data c: " << data.c << std::endl;
	std::cout << "data f: " << data.f << std::endl;
	std::cout << "data d: " << data.d << std::endl;
	std::cout << "Data address: " << &data << std::endl;
	
	uintptr_t serializeIt = Serializer::serialize(&data);
	std::cout << "-----Serialized-----" << std::endl;
	std::cout << "Serialized address: " << serializeIt << std::endl;

	std::cout << "-----Deserialized-----" << std::endl;
	Data* deserializeIt = Serializer::deserialize(serializeIt);
	std::cout << "deserialized data address: " << deserializeIt << std::endl;
	std::cout << deserializeIt->i << std::endl;
	std::cout << deserializeIt->c << std::endl;
	std::cout << deserializeIt->f << std::endl;
	std::cout << deserializeIt->d << std::endl;
	
}