/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:50:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/03 22:45:21 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"

// creates a new Materia (Ice). The base AMateria constructor receives the type "ice"
Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}
	
// creates a new Ice Materia by copying the type from an existing one.
Ice::Ice(const Ice &src) : AMateria(src)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	AMateria::operator=(src);
	return (*this);
}

// destroys the Ice object 'cause AMateria has a virtual destructor 
Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

// creates a new instance of Ice on heap by copying the current object.
// this is essential for deep copy 'cause each Character or MateriaSource must have its own
// independent Materia copy instead of sharing the same instance/pointer.
AMateria *Ice::clone(void) const
{
	Ice *newIce;
	
	newIce = new Ice(*this);
	return (newIce);
}

// when the Ice Materia is used on a character it overrides the base use function to provide specific behavior
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
