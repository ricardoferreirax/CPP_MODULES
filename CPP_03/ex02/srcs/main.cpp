/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:04:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/24 15:32:48 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main(void)
{
	ClapTrap a("Ricky");
	a.attack("Mercury");
	a.takeDamage(5);
	a.beRepaired(3);
	std::cout << "\n--------------------------------------------------------------------------------------" << std::endl;
	ScavTrap b("Blinky");
	b.attack("Inky");
	b.takeDamage(30);
	b.beRepaired(10);
	b.guardGate();
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	FragTrap c("Clyde");
	c.attack("Pinky");
	c.takeDamage(30);
	c.beRepaired(10);
	c.highFivesGuys();
	std::cout << "--------------------------------------------------------------------------------------\n" << std::endl;
	return (0);
}
