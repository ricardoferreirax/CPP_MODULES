/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 23:41:20 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/01 14:43:42 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

// This function creates a Zombie object on the stack and makes it announce itself. 
// The Zombie will be automatically destroyed when the function scope ends.
void randomChump(std::string name)
{
	Zombie zombieOnStack(name);
	
    zombieOnStack.announce();
}
