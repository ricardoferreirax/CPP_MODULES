/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:46:47 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/30 14:47:47 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src)
{

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

AMateria *Cure::clone(void) const
{
	Cure *newCure = new Cure(*this);
	return (newCure);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
