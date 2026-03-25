/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:25:10 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/25 16:29:08 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(void): type("Animal")
{
	std::cout << "Animal default constructor created!" << std::endl;
}

Animal::Animal(const Animal &src): type(src.type)
{
	std::cout << "Animal copy constructor created!" << std::endl;
}

Animal& Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << "Animal copy assignment operator created!" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called!" << std::endl;
}
