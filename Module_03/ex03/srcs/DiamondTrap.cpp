/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:42:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/21 18:33:40 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap [ " << this->_name << " ] default constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap [ " << this->_name << " ] constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "DiamondTrap [ " << this->_name << " ] copy constructed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		this->_name = src._name;
	}
	std::cout << "DiamondTrap [ " << this->_name << " ] copy assigned!" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap [ " << this->_name << " ] destructed!" << std::endl;
}

void DiamondTrap::WhoAmI(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "DiamondTrap [ " << this->_name << " ] is dead! Cannot identify itself!" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap name: [ " << this->_name << " ], ClapTrap name: [ " << ClapTrap::_name << " ]" << std::endl;
}
