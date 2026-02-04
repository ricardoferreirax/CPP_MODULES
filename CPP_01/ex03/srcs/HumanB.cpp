/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:58:39 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/04 23:35:47 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weaponB(NULL)
{
    std::cout << "\nHumanB [" << this->_name << "] has been created unarmed!" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB [" << this->_name << "] has been destroyed!" << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_weaponB)
		std::cout << "HumanB ["<< this->_name << "] attacks with their " << (*this->_weaponB).getType() << std::endl;
	else
		std::cout << "HumanB ["<<this->_name << "] has no weapon to attack with!" << std::endl;
}

void HumanB::setWeapon(Weapon &wp)
{
    this->_weaponB = &wp;
	std::cout << "HumanB ["<<this->_name << "] equipped a " << wp.getType() << std::endl;
}
