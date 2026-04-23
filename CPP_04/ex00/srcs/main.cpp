/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:30:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/23 16:31:12 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
	std::cout << std::endl;
    const Animal* j = new Dog();
	std::cout << std::endl;
    const Animal* i = new Cat();
	
    std::cout << "Animal type: " << j->getType() << " " << std::endl;
    std::cout << "Animal type: " << i->getType() << " " << std::endl;
	std::cout << std::endl;
    std::cout << "Sound: ";
	j->makeSound();
    std::cout << "Sound: ";
	i->makeSound();
	std::cout << "Sound: ";
    meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	std::cout << "\n---------------------------------------------------------------" << std::endl;
	const WrongAnimal* wa = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal* wc = new WrongCat();
	std::cout << std::endl;
	std::cout << "Animal type: ";
	std::cout << wa->getType() << std::endl;
	std::cout << "Animal type: ";
	std::cout << wc->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "Sound: ";
	wa->makeSound();
	std::cout << "Sound: ";
	wc->makeSound();
	std::cout << std::endl;
	delete wa;
	delete wc;

    return (0);
}
