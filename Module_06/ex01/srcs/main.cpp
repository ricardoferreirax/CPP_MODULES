/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:10:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/20 16:47:23 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

#include <iostream>

int	main(int argc, char **argv)
{
	Data *original;
	Data *restored;
	Data car;
	uintptr_t raw;
	(void)argv;
	
	if (argc != 1)
	{
		std::cerr << "Error: use ./serialize" << std::endl;
		return (1);
	}
	car.brand = "Porsche";
	car.year = 2026;
	car.price = 67000;

	original = &car;

	std::cout << std::endl;
	std::cout << "Brand: " << original->brand << std::endl;
	std::cout << "Year:  " << original->year << std::endl;
	std::cout << "Price: " << original->price << std::endl;

	std::cout << "\n--------------------------------------------------\n" << std::endl;

	std::cout << "Original pointer: " << original << std::endl;

	raw = Serializer::serialize(original);
	std::cout << "Serialized value: " << raw << std::endl;

	restored = Serializer::deserialize(raw);
	std::cout << "Restored pointer: " << restored << std::endl;

	std::cout << "\n--------------------------------------------------\n" << std::endl;

	std::cout << "Brand: " << restored->brand << std::endl;
	std::cout << "Year:  " << restored->year << std::endl;
	std::cout << "Price: " << restored->price << std::endl;

	std::cout << "\n--------------------------------------------------\n" << std::endl;

	if (original == restored)
		std::cout << "Success: pointers are equal -> " << (original == restored) << std::endl;
	else
		std::cout << "Error: pointers are different -> " << (original == restored) << std::endl;
	std::cout << std::endl;

	return (0);
}