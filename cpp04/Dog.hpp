/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:25:18 by alli              #+#    #+#             */
/*   Updated: 2024/11/04 13:28:03 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

class Dog : public Animal{
	protected:
		std::string type;
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();
		
		Dog& operator=(const Dog& other);
		void	makeSound(){
			std::cout << "The dog says: woof woof" << std::endl;
		}
};