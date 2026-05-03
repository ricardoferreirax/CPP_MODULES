/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:00:06 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/03 22:32:36 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(void)
{
	this->_type = "default";
	std::cout << "AMateria default constructor called" << std::endl;
}

// creates a base AMateria with a specific type, which is later used to identify the kind of Materia (ice, cure).
AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	std::cout << "AMateria constructor called" << std::endl;
}

// creates a new AMateria by copying the type from another AMateria.
// this is used when a derived class calls clone(), that creates a new object/instance from an existing Ice or Cure.
AMateria::AMateria(const AMateria &src)
{
	this->_type = src._type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

// While assigning a Materia to another, copying the type doesn’t make sense 'cause the concrete
// class type (Ice, Cure) is already defined by the constructor of Ice or Cure.
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

// returns the type of the Materia. MateriaSource uses this to identify which Materia should be cloned
std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

// it does nothing here because the real behavior is defined in Ice::use() and Cure::use().
void AMateria::use(ICharacter &target)
{
	(void)target;
}
