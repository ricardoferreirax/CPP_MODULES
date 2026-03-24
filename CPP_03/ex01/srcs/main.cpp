/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 23:21:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/24 14:18:36 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(void)
{
	std::cout << "---- ClapTrap test ----" << std::endl;
	ClapTrap a("Ricky");
	a.attack("Mercury");
	a.takeDamage(5);
	a.beRepaired(3);
	std::cout << "---- ScavTrap test ----" << std::endl;
	ScavTrap b("Mercury");
	b.attack("target");
	b.takeDamage(30);
	b.beRepaired(10);
	//b.guardGate();

	std::cout << std::endl;
	std::cout << "---- Copy test ----" << std::endl;
	ScavTrap c(b);
	c.attack("another target");

	std::cout << std::endl;
	std::cout << "---- Assignment test ----" << std::endl;
	ScavTrap d;
	d = b;
	//d.guardGate();

	return (0);
}