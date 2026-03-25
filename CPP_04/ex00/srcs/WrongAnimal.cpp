/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:52:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/25 20:53:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->_type = "WrongAnimal";
	std::cout << "\nWrongAnimal default constructor created!" << std::endl;
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
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sound!" << std::endl;
}
