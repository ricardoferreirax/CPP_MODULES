/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:46:47 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/03 22:48:03 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

// creates a new Materia (Cure). The base AMateria constructor receives the type "cure"
Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

// creates a new Cure Materia by copying the type from an existing one.
Cure::Cure(const Cure &src) : AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
	AMateria::operator=(src);
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

// creates a new instance of Cure on heap by copying the current object.
// this is used by Character and MateriaSource to create independent copies of Cure Materia 
AMateria *Cure::clone(void) const
{
	Cure *newCure = new Cure(*this);
	return (newCure);
}

// when the Cure Materia is used on a character it overrides the base use function to provide specific behavior
void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
