/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:34:28 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/04 23:37:17 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string.h>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(void);
		Weapon(std::string _type);
		~Weapon(void);
		const std::string &getType();
		void setType(std::string newType);
};

#endif