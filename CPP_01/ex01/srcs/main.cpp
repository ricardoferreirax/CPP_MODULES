/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:56:09 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/02 14:01:11 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(int ac, char **av)
{
    if (ac != 1)
    {
        std::cout << "Run the program only with: " << av[0] << std::endl;
        return (1);
    }
    /* 
	Zombie z1; // default constructor 
    z1.setName("DefaultZombie");
    z1.announce();
    Zombie z2("ZombieConstructor"); // constructor
    z2.announce(); 
	*/
    std::cout << "\nZombie Horde Creation:" << std::endl;
	Zombie *horde;
	std::string name;
    int N;

	name = "HordeZombie";
    N = 10;
    horde = zombieHorde(N, name);
	if (!horde)
	{
		std::cout << "\nFailed to create the horde!" << std::endl;
		return (1);
	}
    std::cout << "\nZombies Announce Themselves:\n";
    for (int i = 0; i < N; i++)
	{
		// std::cout << "[" << i << "] ";
		horde[i].announce();
	}
    std::cout << "\nZombie Horde Destruction:\n";
    delete [] horde;
    return (0);
}
