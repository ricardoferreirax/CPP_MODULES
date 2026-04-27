/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:46:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/27 10:57:53 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

// it creates a new Dog object and initializes its type to "Dog". It also allocates memory for 
// a new Brain object and assigns it to the _brain pointer. this allows each Dog instance to have 
// its own separate Brain object, which can store its own ideas without affecting other Dog instances.
Dog::Dog(void): AAnimal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor created!" << std::endl;
}

// creates a new Dog object in heap using Brain's copy constructor.
// this ensures that each Dog has its own separate Brain object, preventing shared state between different Dog instances.
// src._brain points to the original Dog brain and *src._brain accesses the real Brain object.
// original._brain (Brain A) and copy._brain (Brain B) are two different Brain objects in memory, 
// but contain the same content ideas, stored separately.
Dog::Dog(const Dog &src): AAnimal(src)
{
	this->_brain = new Brain(*src._brain);
	std::cout << "Dog copy constructor created!" << std::endl;
}

// this is a deep copy which means that the new Dog will have its own separate memory for the Brain object 
// and its ideas, and changes to the Brain or ideas in one Dog will not affect the other Dog.
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
	delete this->_brain;
	std::cout << "Dog destructed!" << std::endl;
}

// Dog class overrides the makeSound() to print "Woof Woof!" instead of the default "Animal sound!" provided by the base class.
void Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}

// returns the animal type stored in the _type member. It is used to identify the real type of the object.
void Dog::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}

// returns the idea stored at the specified index in the _ideas array of the Brain object associated with the Dog
std::string Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
