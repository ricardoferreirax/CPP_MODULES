/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:59:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/04 14:57:53 by rmedeiro         ###   ########.fr       */
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
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void );
};

Zombie*	newZombie( std::string name );
void randomChump( std::string name );

#endif