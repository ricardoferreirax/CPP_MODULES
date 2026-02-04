/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:37:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/04 23:22:24 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(void)
{
	this->_type = "Unassigned Weapon";
	std::cout << this->_type << ": Weapon created with no assigned type\n" << std::endl;
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon [" << this->_type << "] has been created!" << std::endl;
}

Weapon::~Weapon(void)
{	
	std::cout << "Weapon [" << this->_type << "] has been destroyed!\n" << std::endl;
}

const std::string &Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(std::string newType)
{
	this->_type = newType;
	std::cout << "Weapon [" << this->_type << "] has been equipped!"<<std::endl;
}
