/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:26:18 by alli              #+#    #+#             */
/*   Updated: 2024/11/07 16:11:53 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(const Cat& other);
		~Cat()override;
		Cat& operator=(const Cat& other);
		void	makeSound() const override;
		Brain* getBrain();
	
	private:
			Brain* Brain;
};

#endif