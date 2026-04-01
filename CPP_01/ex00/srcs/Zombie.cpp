/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:48:41 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/01 14:12:24 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string Zombie::getName(void) const
{
	return (this->_name);
}

Zombie::Zombie(std::string name)
{
    this->_name = name;
	std::cout << this->_name << " created!" << std::endl;
}

Zombie::~Zombie( void )
{
    std::cout << this->_name << " destroyed!" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
