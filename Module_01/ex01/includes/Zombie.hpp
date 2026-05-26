/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:25:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/01 15:34:10 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
	private:
		std::string _name;
		
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
		
		void	announce( void );

		void	setName(std::string name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif
