/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 23:21:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/21 17:54:14 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(void)
{
	ClapTrap a("Ricky");
	std::cout << std::endl;
	a.attack("Mercury");
	a.takeDamage(5);
	a.beRepaired(3);
	std::cout << std::endl;
	ScavTrap b("Mercury");
	std::cout << std::endl;
	b.attack("Ricky");
	b.takeDamage(300);
	b.beRepaired(10);
	b.guardGate();
	std::cout << std::endl;
	return (0);
}
