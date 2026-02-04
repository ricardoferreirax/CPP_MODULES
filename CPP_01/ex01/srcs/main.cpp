/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:56:09 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/04 16:06:23 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int Nb;

	Nb = 10;
    std::cout << "Zombie Horde Creation: " << std::endl;
	horde = zombieHorde(Nb, "Zombies");
	std::cout << "\n";
	std::cout << "Zombies Announce Themselves: " << std::endl;
	for (int i = 0; i < Nb; i++)
	{
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}
	std::cout << "\n";
	std::cout << "Zombie Horde Destruction: " << std::endl;
	delete [] horde;
	return (0);
}
