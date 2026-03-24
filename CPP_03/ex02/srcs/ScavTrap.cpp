/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:52:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/24 15:32:51 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include <iostream>

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

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "\n"<< "ScavTrap [ " << this->_name << " ] attacks [ " << target 
			<< " ], causing ( " << this->_attackDamage << " ) points of damage!" << std::endl;
	}
	else if (this->_hitPoints == 0)
		std::cout << "ScavTrap [ " << this->_name << " ] is dead! No hit points left!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap [ " << this->_name << " ] has no energy left, so he cannot attack the "
			<< target << "!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->_hitPoints == 0)
		std::cout << "ScavTrap [ " << this->_name << " ] is dead! Cannot enter Gate keeper mode!" << std::endl;
	if (this->_energyPoints == 0)
		std::cout << "ScavTrap [ " << this->_name << " ] has no energy left! Cannot enter Gate keeper mode!" << std::endl;
	std::cout << "ScavTrap [ " << this->_name << " ] has entered Gate keeper mode!" << "\n" << std::endl;
}
