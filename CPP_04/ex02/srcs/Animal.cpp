/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:25:10 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/26 11:02:07 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(void)
{
	this->_type = "Abstract_Animal";
	std::cout << "\nAbstract Animal default constructor created!" << std::endl;
}

Animal::Animal(const Animal &src)
{
	this->_type = src._type;
	std::cout << "Abstract Animal copy constructor created!" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "Abstract Animal copy assignment operator created!" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Abstract Animal destructed!" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}
