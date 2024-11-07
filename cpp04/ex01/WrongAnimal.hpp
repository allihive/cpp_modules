/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:21:51 by alli              #+#    #+#             */
/*   Updated: 2024/11/06 16:26:35 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define	WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& copy);

		std::string getType() const;
		virtual void makeSound() const;
		virtual ~WrongAnimal();
};

#endif