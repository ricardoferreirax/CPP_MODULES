/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:23:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/03 16:55:12 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie( void )
{
    std::cout << "Zombie default constructor called" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
	std::cout << "Setting zombie name to: " << name << std::endl;
	this->name = name;
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
