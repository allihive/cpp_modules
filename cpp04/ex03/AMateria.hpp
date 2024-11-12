/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:26:35 by alli              #+#    #+#             */
/*   Updated: 2024/11/08 17:33:31 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter
{
	public: 
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

};

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(std::string const & type);
		AMateria();
		AMateria& operator=(const AMateria&);
		virtual ~AMateria();

		std::string const &getType() const;
		virtual AMateria* clone () const = 0;
		virtual void use(ICharacter& target);
		
};

#endif