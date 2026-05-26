/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 23:31:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/01 14:44:05 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

// This function creates a Zombie on the heap.
// Returns a pointer to the created Zombie so we can use it outside of the function scope.
Zombie	*newZombie(std::string name)
{
	Zombie *zombieOnHeap;
	
	zombieOnHeap = new Zombie(name);
	return (zombieOnHeap);
}
