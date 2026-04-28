/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:25:10 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/28 16:16:38 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(void)
{
	this->_type = "Animal";
	std::cout << "Animal default constructor created!" << std::endl;
}

Animal::Animal(const Animal &src)
{
	this->_type = src._type;
	std::cout << "Animal copy constructor created!" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "Animal copy assignment operator created!" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructed!" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

// returns the base Animal class sound. this function is virtual, which means that it can 
// be overridden by derived classes to provide specific sounds for different types of animals.
// this allows us to have different behaviours for different types while still using a common base class interface.
void Animal::makeSound(void) const
{
	std::cout << "Animal sound!" << std::endl;
}
