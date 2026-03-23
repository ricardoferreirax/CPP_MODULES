/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:02:50 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/23 22:47:45 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap [ " << this->_name << " ] default constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap [ " << this->_name << " ] constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src): 
	_name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
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

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap [ " << this->_name << " ] attacks [ " << target 
			<< " ], causing ( " << this->_attackDamage << " ) points of damage!" << std::endl;
	}
	else if (this->_hitPoints <= 0)
		std::cout << "ClapTrap [ " << this->_name << " ] is dead! No hit points left!" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "ClapTrap [ " << this->_name << " ] has no energy left, so he cannot attack the " 
			<< target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		if (amount >= this->_hitPoints)
		{
			this->_hitPoints = 0;
			std::cout << "ClapTrap [ " << this->_name << " ] takes ( " << amount 
				<< " ) points of damage and dies! Remaining hit points: ( " << this->_hitPoints << " )" 
				<< std::endl;
		}
		else if (amount < this->_hitPoints)
		{
			this->_hitPoints -= amount;
			std::cout << "ClapTrap [ " << this->_name << " ] takes ( " << amount 
				<< " ) points of damage! Remaining hit points: ( " << this->_hitPoints << " )" << std::endl;
		}
	}
	else if (this->_hitPoints <= 0)
		std::cout << "ClapTrap [ " << this->_name << " ] is already dead! No hit points left!" << std::endl;
}
