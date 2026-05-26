/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:24:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/03 22:08:12 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

// AMateria is abstract 'cause it contains at least one pure virtual function (clone). 
// it serves as a base class for Ice and Cure types that will implement the clone method 
// to allow copying of Materia objects through a common interface.
class AMateria
{
	protected:
		std::string _type;
		
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &src);
		AMateria &operator=(const AMateria &src);
		virtual ~AMateria(void);

        std::string const &getType(void) const;
		
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif
