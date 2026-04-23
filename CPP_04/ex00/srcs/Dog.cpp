/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:46:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/23 14:48:58 by rmedeiro         ###   ########.fr       */
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

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
		Animal::operator=(src);
	std::cout << "Dog copy assignment operator created!" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructed!" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}
