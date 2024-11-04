/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:26:18 by alli              #+#    #+#             */
/*   Updated: 2024/11/04 15:25:35 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();
		
		Cat& operator=(const Cat& other);
		void	makeSound();
};