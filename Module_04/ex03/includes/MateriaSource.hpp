/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:46:02 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/30 16:49:18 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materias[4];
		
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		MateriaSource &operator=(const MateriaSource &src);
		~MateriaSource(void);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif
