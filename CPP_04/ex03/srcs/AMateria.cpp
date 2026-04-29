/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:00:06 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/29 16:59:15 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(void)
{
	this->_type = "default";
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	this->_type = src._type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "AMateria copy assignment operator called" << std::endl;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria used on " << target.getName() << std::endl;
}
