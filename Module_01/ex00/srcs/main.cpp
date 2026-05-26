/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:20:18 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/01 15:15:58 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie *zombie;

	std::cout << "\nCreating zombie on the heap..." << std::endl;
	zombie = newZombie("HeapZombie");
	std::cout << "\nThe zombie announces itself...\n";
	zombie->announce();
	std::cout << std::endl;
	delete zombie;
	std::cout << "\n----------------------------------------\n";
	std::cout << "\nCreating zombie on the stack..." << std::endl;
	randomChump("StackZombie");
	std::cout << "\n----------------------------------------\n";
	std::cout << "\nCreating another stack zombie..." << std::endl;
	{
		Zombie scopedZombie("ScopedZombie");
		std::cout << "\nThe zombie announces itself...\n";
		scopedZombie.announce();
		std::cout << "\nLeaving the scope block...\n";
	}
	return (0);
}
