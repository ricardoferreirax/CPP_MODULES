/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:20:18 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/02 23:57:26 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(void)
{
    std::cout << "Creating a zombie on the heap:" << std::endl;
    Zombie *heapZombie = newZombie("Ricardo");
    heapZombie->announce();
    delete (heapZombie);
    std::cout << std::endl;
    std::cout << "Creating a zombie on the stack:" << std::endl;
    randomChump("Mercury");
    return (0);
}
