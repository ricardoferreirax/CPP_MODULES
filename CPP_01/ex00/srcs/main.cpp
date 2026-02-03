/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:20:18 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/03 23:06:57 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	std::cout << "Creating zombie on the heap:" << RESET << std::endl;
	Zombie *zombieOnHeap = newZombie("HeapZombie");
	zombieOnHeap->announce();
	delete (zombieOnHeap);
	std::cout << std::endl << "Creating zombie on the stack:" << std::endl;
	randomChump("StackZombie");
	std::cout << std::endl << "Creating another stack zombie in a local scope:" << std::endl;
	{
		Zombie scopedZombie("ScopedZombie");
		scopedZombie.announce();
	}
	return (0);
}
