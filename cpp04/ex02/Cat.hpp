/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:26:18 by alli              #+#    #+#             */
/*   Updated: 2024/11/08 11:36:21 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain* brainz;
	public:
		Cat();
		Cat(const Cat& other);
		~Cat() override;
		Cat& operator=(const Cat& other);
		void	makeSound() const override;
		Brain* getBrain();
};

#endif