/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:30:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/27 13:33:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	AAnimal *animals[6];

	// this does not compile because AAnimal is an abstract class due to the presence of the pure virtual function makeSound().
	
	// AAnimal animal;
	// AAnimal *meta = new AAnimal();

	// but ppointers/references to AAnimal can be created and used to point to objects of derived classes like Dog and Cat, 
	// allowing for polymorphic behavior when calling virtual functions through these pointers/references.
	
	for (int i = 0; i < 3; i++)
		animals[i] = new Dog();
	std::cout << std::endl;
	for (int i = 3; i < 6; i++)
		animals[i] = new Cat();
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
		delete animals[i];
	std::cout << "\n---------------------------------------------------------------" << std::endl;
	
	Cat cat_og;
	std::cout << std::endl;
	cat_og.setIdea(0, "I want a fish");
	std::cout << "Orginal cat ideia: " << cat_og.getIdea(0) << std::endl;
	Cat copy_cat = cat_og;
	copy_cat.setIdea(0, "I want to sleep");
	std::cout << "Copy cat ideia: " << copy_cat.getIdea(0) << std::endl;
	std::cout << std::endl;
	Dog dog_og;
	std::cout << std::endl;
	dog_og.setIdea(0, "I want a bone");
	std::cout << "Original idea: " << dog_og.getIdea(0) << std::endl;
	Dog dog_copy = dog_og;
	dog_copy.setIdea(0, "I want to bark");
	std::cout << "Copy idea: " << dog_copy.getIdea(0) << std::endl;
	std::cout << std::endl;

	const WrongAnimal *wrong = new WrongCat();
	std::cout << "WrongAnimal type: " << wrong->getType() << std::endl;
	std::cout << "WrongAnimal sound: ";
	wrong->makeSound();

	// because makesound() in WrongAnimal is not virtual, this calls WrongAnimal::makesound() instead of WrongCat::makeSound()
	std::cout << std::endl;
	delete wrong;

    return (0);
}


