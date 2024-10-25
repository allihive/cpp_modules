/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:25:21 by alli              #+#    #+#             */
/*   Updated: 2024/10/24 14:41:27 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
	private:
		void debug ();
		void info ();
		void warning ();
		void error();
	public:
		void complain( std::string level );
};
int findLevel(std::string line);
typedef void (Harl::*c_func)(void);

#endif