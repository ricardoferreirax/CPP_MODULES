/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:48:09 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/02 11:59:46 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

int main(void)
{
	IMateriaSource *src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	std::cout << std::endl;
	
	src->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter *me = new Character("me");
	std::cout << std::endl;
	
	AMateria *tmp;

	tmp = src->createMateria("ice");
	std::cout << std::endl;
	me->equip(tmp);
	std::cout << std::endl;
	
	tmp = src->createMateria("cure");
	std::cout << std::endl;
	me->equip(tmp);
	std::cout << std::endl;
	
	ICharacter *bob = new Character("bob");
	std::cout << std::endl;
	
	me->use(0, *bob);
	std::cout << std::endl;
	me->use(1, *bob);
	std::cout << std::endl;
	
	delete bob;
	delete me;
	delete src;

	return (0);
}
