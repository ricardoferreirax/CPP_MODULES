/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:46:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/25 17:00:46 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void): Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor created!" << std::endl;
}

Dog::Dog(const Dog &src): Animal(src)
{
	std::cout << "Dog copy constructor created!" << std::endl;
}

Dog& Dog::operator=(const Dog &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "Dog copy assignment operator created!" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
