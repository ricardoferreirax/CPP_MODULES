/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:08:54 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/17 22:26:12 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("Default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap [ " << this->_name << " ] default constructed!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap [ " << this->_name << " ] constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	std::cout << "FragTrap [ " << this->_name << " ] copy constructed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
		ClapTrap::operator=(src);	
	std::cout << "FragTrap [ " << this->_name << " ] copy assigned!" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap [ " << this->_name << " ] destructed!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
		std::cout << "FragTrap [ " << this->_name << " ] is dead! Cannot give a high five!" << "\n" << std::endl;
	else
		std::cout << "FragTrap [ " << this->_name << " ] gives a high five!" << "\n" << std::endl;
}
