/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:30:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/26 10:34:14 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	Animal *animals[6];

	for (int i = 0; i < 3; i++)
		animals[i] = new Dog();
	for (int i = 3; i < 6; i++)
		animals[i] = new Cat();
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
		delete animals[i];
	std::cout << "\n---------------------------------------------------------------" << std::endl;
	
	Cat cat_orginal;
	std::cout << std::endl;
	cat_orginal.setIdea(0, "I want a fish");
	Cat copy_cat = cat_orginal;
	copy_cat.setIdea(0, "I want to sleep");
	std::cout << std::endl;
	std::cout << "Original cat idea: " << cat_orginal.getIdea(0) << std::endl;
	std::cout << "Copy cat idea: " << copy_cat.getIdea(0) << std::endl;
	std::cout << "\n---------------------------------------------------------------" << std::endl;	

	Dog dog_original;
	std::cout << std::endl;
	dog_original.setIdea(0, "I want a bone");
	Dog dog_copy = dog_original;
	dog_copy.setIdea(0, "I want to bark");
	std::cout << std::endl;
	std::cout << "Original idea: " << dog_original.getIdea(0) << std::endl;
	std::cout << "Copy idea: " << dog_copy.getIdea(0) << std::endl;
	std::cout << "\n---------------------------------------------------------------\n" << std::endl;	

    return 0;
}

