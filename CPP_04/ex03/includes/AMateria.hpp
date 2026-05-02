/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:24:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/02 11:14:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

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
