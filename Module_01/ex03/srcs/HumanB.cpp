/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:58:39 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/06 16:27:18 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weaponB(NULL)
{
    std::cout << this->_name << " has been created unarmed!" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << this->_name << " has been destroyed!" << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_weaponB)
		std::cout << this->_name << " attacks with their " << (*this->_weaponB).getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with!" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weaponB = &weapon;
	std::cout << this->_name << " equipped a " << weapon.getType() << std::endl;
}
