/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:31:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/28 15:40:36 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

// allocates memory for a new Brain object and assigns it to the _brain pointer
// this allows each Cat to have its own separate Brain object which can store its 
// own ideas without affecting other Cat
Cat::Cat(void): Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor created!" << std::endl;
	this->_brain = new Brain();
}

// creates a new Cat in heap using Brain's copy constructor.
// this ensures that each Cat has its own separate Brain object, preventing shared state between different Cat instances.
Cat::Cat(const Cat &src): Animal(src)
{
	std::cout << "Cat copy constructor created!" << std::endl;
	this->_brain = new Brain(*src._brain);
}

// deep copy: means that the new Cat will have its own separate memory for the Brain object 
// and its ideas and the changes to the Brain or ideas in one Cat will not affect the other Cat.
// original and copy are two different Brain objects in memory, but contain the same content ideas, stored separately.
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
	delete this->_brain;
	std::cout << "Cat destructed!" << std::endl;
}

// Cat class overrides the makeSound() to print the specific sound instead of the base class
void Cat::makeSound(void) const
{
	std::cout << "Meow Meow!" << std::endl;
}

// returns the animal type stored in the _type member. It is used to identify the real type of the object.
void Cat::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}

// returns the idea stored at the specified index in the _ideas array of the Brain object associated with the Cat
std::string Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
