/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:18:19 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/21 17:20:54 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/* int main()
{
	ClapTrap a("Ricky");
	ClapTrap b("Mercury");
	ClapTrap c(a);

	a.attack("Mercury");
	b.takeDamage(10);
	b.beRepaired(0);
	c.attack("Mercury");
	c.takeDamage(15);
	c.beRepaired(6);
	return (0);
} */

int	main(void)
{
	ClapTrap a("Ricky");
	ClapTrap b("Mercury");
	ClapTrap c(a);
	std::cout << std::endl;
	a.attack("Mercury");
	b.takeDamage(5);
	b.beRepaired(3);
	std::cout << std::endl;
	c.takeDamage(15);
	c.attack("Mercury");
	c.beRepaired(5);
	std::cout << std::endl;
	return (0);
}