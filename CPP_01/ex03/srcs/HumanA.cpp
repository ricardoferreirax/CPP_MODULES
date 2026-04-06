/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:27:20 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/06 15:11:38 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weaponA(weapon)
{
     std::cout << this->_name << " has been created with a weapon!" << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << this->_name << " has been destroyed!" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weaponA.getType() << std::endl;
}
