/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:21:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/03 23:30:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

// deletes all Materias that were unequipped/removed from the inventory with unequip().
// since unequipped Materias are stored in a linked list (floor), we need to traverse it and delete each Materia.
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

// creates a default Character with an empty inventory, so every slot is initialized to NULL
Character::Character(void)
{
	this->_name = "default";
	this->_unequipMateria = NULL;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

// creates a Character with a specific name and with an empty inventory
Character::Character(std::string name)
{
	this->_name = name;
	this->_unequipMateria = NULL;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

// creates a new Character using deep copy to another Character.
// Each Materia is cloned so both Characters have their own independent Materia instances in memory.
Character::Character(const Character &src)
{
	this->_name = src._name;
	this->_unequipMateria = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

// assigns one Character to another using deep copy. First, the current Character delete its old 
// inventory and floor Materias, then it deep copies the inventory from the source Character by cloning each Materia.
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
				this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
}

// the character owns the equipped Materias and also the unequipped Materias (stored in the floor list)
// so the destructor must delete all of them to prevent memory leaks.
Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	deleteUnequippedMateria(&this->_unequipMateria);
}

// returns the character's name. Ice and Cure use this to print the target's name.
std::string const &Character::getName(void) const
{
	return (this->_name);
}

// equips a Materia in the first empty invetory slot.
// if the invetory is full, the character cannot store the new Materia and it is deleted.
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
	delete m;
}

// removes a Materia from the inventory without deleting it. The removed Materia is stored 
// in a linked list (floor) so it can be deleted later by the destructor.
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

// uses the Materia stored in the specified inventory index slot on the target character.
// If the slot is empty or invalid, nothing happens.
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
}
