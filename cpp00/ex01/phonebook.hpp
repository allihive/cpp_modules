/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:49:59 by alli              #+#    #+#             */
/*   Updated: 2024/10/17 09:28:57 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

#include "contact.hpp"

class Phonebook {
	private:
		Contact	contacts[8];
		int		contactCount;
		int		lastContact;
	public:
		Phonebook();
		~Phonebook(); // ask yunchia why
		
		void	addContact();
		void	searchContact();
		bool	displayContact();
		void	createTable();
		void	searchIndex();
};

#endif