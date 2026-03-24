/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:04:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/24 15:06:18 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(void)
{
	std::cout << "----- ClapTrap -----" << std::endl;
	ClapTrap a("Ricky");
	a.attack("enemy");
	a.takeDamage(5);
	a.beRepaired(2);
	std::cout << std::endl;
	std::cout << "----- ScavTrap -----" << std::endl;
	ScavTrap b("Mercury");
	b.attack("target");
	b.takeDamage(30);
	b.beRepaired(10);
	b.guardGate();
	std::cout << std::endl;
/* 	std::cout << "----- FragTrap -----" << std::endl;
	FragTrap c("Venus");
	c.attack("boss");
	c.takeDamage(20);
	c.beRepaired(15);
	c.highFivesGuys(); */
	return (0);
}
