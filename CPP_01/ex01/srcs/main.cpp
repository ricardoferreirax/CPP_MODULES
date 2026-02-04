/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:56:09 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/04 16:11:42 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(int ac, char **av)
{
    Zombie *horde;
    int Nb;

    if (ac != 1)
    {
        std::cout << "Run the program only with: " << av[0] << std::endl;
        return (1);
    }
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
