/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:31:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/28 16:03:43 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void): Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor created!\n" << std::endl;
}

Cat::Cat(const Cat &src): Animal(src)
{
	std::cout << "Cat copy constructor created!" << std::endl;
}

Cat& Cat::operator=(const Cat &src)
{
	if (this != &src)
		Animal::operator=(src);
	std::cout << "Cat copy assignment operator created!" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructed!" << std::endl;
}

// Cat class overrides the makeSound() to print the specific sound instead of the base class
void Cat::makeSound(void) const
{
	std::cout << "Meow Meow!" << std::endl;
}
