/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:46:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/26 14:11:12 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void): AAnimal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor created!" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src): AAnimal(src)
{
	std::cout << "Dog copy constructor created!" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		AAnimal::operator=(src);
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	std::cout << "Dog copy assignment operator created!" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructed!" << std::endl;
	delete this->_brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
