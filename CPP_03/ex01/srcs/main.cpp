/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 23:21:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/24 14:55:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(void)
{
	ClapTrap a("Ricky");
	a.attack("Mercury");
	a.takeDamage(5);
	a.beRepaired(3);
	std::cout << "\n--------------------------------------------------------------------------------------" << std::endl;
	ScavTrap b("Mercury");
	b.attack("Ricky");
	b.takeDamage(30);
	b.beRepaired(10);
	b.guardGate();
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	return (0);
}
