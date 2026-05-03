/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:00:06 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/03 22:07:35 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(void)
{
	this->_type = "default";
	std::cout << "AMateria default constructor called" << std::endl;
}

// we create an AMateria with a specific type, which will be used to identify the 
// kind of Materia (ice, cure).
AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	std::cout << "AMateria constructor called" << std::endl;
}

// we create a new AMateria by copying the type from an existing one.
// this is used when clone() is called on a derived class (Ice or Cure) to create a new instance of the same type.
AMateria::AMateria(const AMateria &src)
{
	this->_type = src._type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

// we don't need to copy anything for AMateria, because the type is set in the constructor and doesn't change.
AMateria &AMateria::operator=(const AMateria &src)
{
	(void)src;
	return (*this);
}

// the destructor is virtual to ensure that the correct destructor is called for derived classes (Ice, Cure) 
// when an AMateria pointer is deleted.
AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

// returns the type of the Materia, which is used to identify it (ice, cure).
std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
