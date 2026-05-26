/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:26:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/14 13:47:33 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

// This function creates an array of N Zombies on the heap, each initialized with the same name.
Zombie* zombieHorde( int N, std::string name )
{
    Zombie *horde;

    if (N <= 0)
    {
        std::cout << "The horde needs at least one Zombie!" << std::endl;
        return (NULL);
    }
    horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return (horde);
}
