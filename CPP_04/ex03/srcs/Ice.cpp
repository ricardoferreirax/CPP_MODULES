/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:50:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/02 11:06:32 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src)
{

}

Ice &Ice::operator=(const Ice &src)
{
	AMateria::operator=(src);
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone(void) const
{
	Ice *newIce = new Ice(*this);
	return (newIce);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
