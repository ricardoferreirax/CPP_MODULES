/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:57:51 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/25 21:29:07 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor created!\n" << std::endl;
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
	
void WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
