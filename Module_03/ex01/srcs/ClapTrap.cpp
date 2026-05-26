/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:02:50 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/21 17:22:58 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap [ " << this->_name << " ] default constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap [ " << this->_name << " ] constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "ClapTrap [ " << this->_name << " ] copy constructed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	std::cout << "ClapTrap [ " << this->_name << " ] copy assigned!" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap [ " << this->_name << " ] destructed!" << std::endl;
}

// If the ClapTrap has hit and energy points, it simulates an attack on a target. It takes only one energy point.
void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack because it has no hit points left!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack because it has no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage
		<< " points of damage!" << std::endl;
}

// If the ClapTrap has hit points, it takes damage and reduces its hit points by the specified amount. 
// If the damage exceeds the current hit points, the ClapTrap's hit points are set to zero.
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead! No hit points left!"  << std::endl;
		return ;
	}
	if (amount >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount 
		<< " points of damage and dies! Current HP: " << this->_hitPoints << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount 
		<< " points of damage! Current HP: " << this->_hitPoints << std::endl;
}

// If the ClapTrap has hit and energy points, it repairs itself by increasing its hit points by the specified amount. 
// It takes only one energy point.
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name 
			<< " cannot be repaired because it has no hit points left!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " cannot be repaired because it has no energy points left!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " repairs itself, recovering " << amount
		<< " hit points! Current HP: " << this->_hitPoints << std::endl;
}
