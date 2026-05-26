/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:49:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/03 23:48:45 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

// creates an empty MateriaSource with all slots initialized to NULL, ready to learn new Materias.
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

// creates a new MateriaSource by deep copying the Materias from another MateriaSource.
// each stored Materia is cloned, so both MateriaSources have their own independent copies of the Materias in memory.
MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._materias[i])
		{
			this->_materias[i] = src._materias[i]->clone();
			std::cout << "Cloning materia in slot " << i << " from source MateriaSource" << std::endl;
		}
		else
			this->_materias[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

// assigns one MateriaSource to another using deep copy. First, the current MateriaSource deletes its old
// Materias, then it deep copies the Materias from the source MateriaSource by cloning each Materia.
MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
			{
				delete this->_materias[i];
				std::cout << "Deleted existing materia in slot " << i << " on MateriaSource" << std::endl;
				this->_materias[i] = NULL;
			}
			if (src._materias[i])
			{
				this->_materias[i] = src._materias[i]->clone();
				std::cout << "Cloned materia in slot " << i << " from source MateriaSource" << std::endl;
			}
			else
				this->_materias[i] = NULL;
		}
	}
	return (*this);
}

// deletes the MateriaSource that owns the learned Materias, so it must delete every stored Materia,
MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
		{
			delete this->_materias[i];
			std::cout << "Deleted materia in slot " << i << " on MateriaSource destructor" << std::endl;
			this->_materias[i] = NULL;
		}
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

// learns a new Materia by cloning the provided Materia parameter.
// if the MateriaSource has an empty slot, it stores the cloned Materia there and deletes
// the original Materia passed as parameter.
void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "Cannot learn a NULL materia!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = m->clone();
			std::cout << "Learned " << m->getType() << " materia in slot " << i << std::endl;
			delete m;
			return ;
		}
	}
	std::cout << "MateriaSource inventory is full! Cannot learn more materia!" << std::endl;
	delete m;
}

// creates a new Materia from one of the learned Materias. If the requested type matches a learned Materia, 
//it clones that Materia and returns the new instance. If the type is not found, it returns NULL.
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			std::cout << "Creating materia of type " << type << " from slot " << i << std::endl;
			return (this->_materias[i]->clone());
		}
	}
	std::cout << "Materia of type " << type << " not found in MateriaSource!" << std::endl;
	return (NULL);
}
