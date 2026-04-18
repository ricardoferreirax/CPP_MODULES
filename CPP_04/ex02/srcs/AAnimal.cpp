/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:25:10 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/18 22:37:48 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal(void)
{
	this->_type = "Abstract_Animal";
	std::cout << "\nAbstract Animal default constructor created!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	this->_type = src._type;
	std::cout << "Abstract Animal copy constructor created!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "Abstract Animal copy assignment operator created!" << std::endl;
	return (*this);
}
	
AAnimal::~AAnimal(void)
{
	std::cout << "Abstract Animal destructed!" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}
