/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:52:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/27 13:15:35 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->_type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	this->_type = src._type;
	std::cout << "WrongAnimal copy constructor created!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "WrongAnimal copy assignment operator created!" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructed!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

// returns the default sound for the base WrongAnimal class. this function is not virtual, which means that
// it cannot be overridden by derived classes to provide specific sounds for different types of animals.
void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sound!" << std::endl;
}
