/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:46:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/23 17:23:13 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void): Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor created!" << std::endl;
}

Dog::Dog(const Dog &src): Animal(src)
{
	this->_brain = new Brain(*src._brain);
	std::cout << "Dog copy constructor created!" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	std::cout << "Dog copy assignment operator created!" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog destructed!" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
