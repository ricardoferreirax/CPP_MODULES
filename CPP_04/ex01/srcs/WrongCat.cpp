/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:57:51 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/28 15:54:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor created!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		WrongAnimal::operator=(src);
	std::cout << "WrongCat copy assignment operator created!" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructed!" << std::endl;
}

// as the makeSound() function in WrongAnimal is not declared as virtual, the WrongCat class 
// cannot override it properly so polymorphism does not work as expected through a WrongANimal pointer or reference
void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow" << std::endl;
}
