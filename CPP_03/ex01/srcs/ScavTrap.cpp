/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:52:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/21 17:53:38 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("Default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap [ " << this->_name << " ] default constructed!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap [ " << this->_name << " ] constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	std::cout << "ScavTrap [ " << this->_name << " ] copy constructed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
		ClapTrap::operator=(src);	
	std::cout << "ScavTrap [ " << this->_name << " ] copy assigned!" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap [ " << this->_name << " ] destructed!" << std::endl;
}

// If the ScavTrap has hit and energy points, it simulates an attack on a target. It takes only one energy point.
void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack because it has no HP left!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack because it has no EP left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage
		<< " points of damage!" << std::endl;
}

// If the ScavTrap has hit and energy points, it simulates entering Gate keeper mode. It takes only one energy point.
void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot enter Gate keeper mode because it has no HP left!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
