/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:48:41 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/04 15:52:30 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
	std::cout << this->_name << " has been created!" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << "\nDestroying " << this->_name << "..." << std::endl;
    std::cout << this->_name << " has been destroyed!" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
