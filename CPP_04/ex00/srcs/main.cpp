/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:30:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/25 20:54:57 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
	delete meta;
	delete j;
	delete i;
	
	const WrongAnimal* wa = new WrongAnimal();
	//const WrongAnimal* wc = new WrongCat();

	std::cout << wa->getType() << std::endl;
	//std::cout << wc->getType() << std::endl;
	wa->makeSound();
	//wc->makeSound();
	delete wa;
	//delete wc;

    return 0;
}
