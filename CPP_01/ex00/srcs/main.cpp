/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:20:18 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/04 15:55:58 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 1)
	{
		std::cout << "Run the program only with: " << av[0] << std::endl;
		return (1);
	}
	std::string heapName = "HeapZombie";
	std::string stackName = "StackZombie";
	std::string scopeName = "ScopedZombie";

	std::cout << "\n[1] HEAP ALLOCATION (newZombie)\n\n";
	std::cout << "Creating zombie on the heap..." << std::endl;
	Zombie *zombieOnHeap = newZombie(heapName);
	std::cout << "\nThe zombie announces itself...\n";
	zombieOnHeap->announce();
	delete zombieOnHeap;
	std::cout << "\n----------------------------------------\n";

	std::cout << "[2] STACK ALLOCATION (randomChump)\n";
	std::cout << "\nCreating zombie on the stack..." << std::endl;
	randomChump(stackName);
	std::cout << "\n----------------------------------------\n";

	std::cout << "[3] STACK ALLOCATION (local scope)\n";
	std::cout << "\nCreating another stack zombie..." << std::endl;
	{
		Zombie scopedZombie(scopeName);
		std::cout << "\nThe zombie announces itself...\n";
		scopedZombie.announce();
		std::cout << "\nLeaving the scope block...\n";
	}
	std::cout << "\n----------------------------------------\n";
	std::cout << "\nAll stack objects are already destroyed.\n";
	return (0);
}
