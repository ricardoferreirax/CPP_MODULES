/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:46:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/28 15:53:03 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

// allocates memory for a new Brain object and assigns it to the _brain pointer
// this allows each Dog to have its own separate Brain object which can store its 
// own ideas without affecting other Dog
Dog::Dog(void): Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor created!" << std::endl;
}

// creates a new Dog in heap using Brain's copy constructor.
// this ensures that each Dog has its own separate Brain object, preventing shared state between different Dog instances.
Dog::Dog(const Dog &src): Animal(src)
{
	this->_brain = new Brain(*src._brain);
	std::cout << "Dog copy constructor created!" << std::endl;
}

// deep copy: means that the new Dog will have its own separate memory for the Brain object 
// and its ideas and the changes to the Brain or ideas in one Dog will not affect the other Dog.
// original and copy are two different Brain objects in memory, but contain the same content ideas, stored separately.
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

// Dog class overrides the makeSound() to print the specific sound instead of the base class
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
