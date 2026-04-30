/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:51:01 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/30 16:21:35 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

typedef struct s_floor
{
	AMateria *materia;
	struct s_floor *next;
}	t_floor;

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
		t_floor *_unequipMateria;

	public:
		Character(void);
		Character(std::string name);
		Character(const Character &src);
		Character &operator=(const Character &src);
		~Character(void);

		std::string const &getName(void) const;
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif
