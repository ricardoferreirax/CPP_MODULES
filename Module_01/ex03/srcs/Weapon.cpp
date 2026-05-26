/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:37:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/06 16:33:29 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << "Weapon [" << this->_type << "] has been created!" << std::endl;
}

Weapon::~Weapon(void)
{	
	std::cout << "Weapon [" << this->_type << "] has been destroyed!\n" << std::endl;
}

const std::string &Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string newType)
{
	this->_type = newType;
	std::cout << "Weapon [" << this->_type << "] has been equipped!"<<std::endl;
}
