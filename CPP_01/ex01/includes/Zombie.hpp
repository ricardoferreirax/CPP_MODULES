/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:25:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/03 16:49:26 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
	private:
		std::string name;
	public:
        Zombie( void ); // * Default Constructor
		~Zombie(); // * Destructor
		void	setName(std::string name);
		void	announce( void );
};


#endif