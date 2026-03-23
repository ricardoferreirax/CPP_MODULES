/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:18:19 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/23 22:29:37 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
	ClapTrap a("Ricky");
	ClapTrap b("Mercury");
	ClapTrap c(a);

	a.attack("Mercury");
	/* b.takeDamage(0);
	b.beRepaired(0); */
	c.attack("Mercury");
	/* c.takeDamage(0);
	c.beRepaired(0);*/
	return (0);
}
