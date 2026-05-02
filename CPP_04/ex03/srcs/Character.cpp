/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:21:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/02 11:32:31 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

static void	deleteUnequippedMateria(t_floor **unequipMateria)
{
	t_floor *current;
	t_floor *next;

	current = *unequipMateria;
	while (current)
	{
		next = current->next;
		if (current->materia)
		{
			std::cout << "Deleting unequipped materia " << current->materia->getType() 
			          << " from floor" << std::endl;
			delete current->materia;
		}
		delete current;
		current = next;
	}
	*unequipMateria = NULL;
}

Character::Character(void)
{
	this->_name = "default";
	this->_unequipMateria = NULL;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name)
{
	this->_name = name;
	this->_unequipMateria = NULL;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character &src)
{
	this->_name = src._name;
	this->_unequipMateria = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
		{
			this->_inventory[i] = src._inventory[i]->clone();
			std::cout << "Cloning materia in inventory slot " << i << " from source Character" << std::endl;
		}
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(Character const &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			std::cout << "Deleted existing materia in inventory slot " << i 
			          << " on Character" << std::endl;
			this->_inventory[i] = NULL;
		}
		deleteUnequippedMateria(&this->_unequipMateria);
		for (int i = 0; i < 4; i++)
		{
			if (src._inventory[i])
			{
				this->_inventory[i] = src._inventory[i]->clone();
				std::cout << "Cloned materia in inventory slot " << i 
						  << " from source Character" << std::endl;
			}
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	deleteUnequippedMateria(&this->_unequipMateria);
}

/* Character::~Character(void)
{
	t_floor *current;
	t_floor *next;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			std::cout << this->_name << ": Deleting equipped materia "
					  << this->_inventory[i]->getType() << " from slot " << i << std::endl;
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	current = this->_unequipMateria;
	while (current)
	{
		next = current->next;
		if (current->materia)
		{
			std::cout << this->_name << ": Deleting unequipped materia "
					  << current->materia->getType() << " from floor" << std::endl;
			delete current->materia;
		}
		delete current;
		current = next;
	}
	std::cout << "Character destructor called" << std::endl;
} */

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << this->_name << ": Cannot equip a NULL materia!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << this->_name << ": Equipped " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << this->_name << ": Inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	t_floor *newFloor;
	
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
		return ;
	newFloor = new t_floor;
	newFloor->materia = this->_inventory[idx];
	newFloor->next = this->_unequipMateria;
	this->_unequipMateria = newFloor;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
	{
		std::cout << this->_name << ": No materia equipped in this slot! Slot: " << idx << " is invalid!" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
	{
		std::cout << this->_name << ": Using " << this->_inventory[idx]->getType() << " on " << target.getName() << std::endl;
		this->_inventory[idx]->use(target);
		return ;
	}
	std::cout << this->_name << ": No materia equipped in this slot! Slot: " << idx << " is empty!" << std::endl;
}
