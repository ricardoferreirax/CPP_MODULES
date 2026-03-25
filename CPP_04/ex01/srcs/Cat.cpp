/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:31:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/25 22:19:00 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void): Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor created!" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src): Animal(src)
{
	std::cout << "Cat copy constructor created!" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	std::cout << "Cat copy assignment operator created!" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructed!" << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
