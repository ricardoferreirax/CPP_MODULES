/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:10:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/20 22:14:39 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

#include <iostream>

int	main(int argc, char **argv)
{
	Data car;
	Data *original;
	Data *restored;
	uintptr_t raw;

	(void)argv;
	if (argc != 1)
	{
		std::cerr << "Use: ./Serialize" << std::endl;
		return (1);
	}
	car.brand = "Porsche";
	car.year = 2024;
	car.price = 135000;

	original = &car;

	std::cout << "\n--------------------------------------------------------\n" << std::endl;

	std::cout << "Brand: " << car.brand << std::endl;
	std::cout << "Year: " << car.year << std::endl;
	std::cout << "Price: " << car.price << " EUR" << std::endl;

	std::cout << "\n--------------------------------------------------------\n" << std::endl;

	std::cout << "Original address: " << original << std::endl;
	
	raw = Serializer::serialize(original);
	std::cout << "Serialized address: " << raw << std::endl;
	
	restored = Serializer::deserialize(raw);
	std::cout << "Restored address: " << restored << std::endl;

	std::cout << "\n--------------------------------------------------------\n" << std::endl;

	std::cout << "Brand: " << restored->brand << std::endl;
	std::cout << "Year: " << restored->year << std::endl;
	std::cout << "Price: " << restored->price << " EUR" << std::endl;

	std::cout << "\n--------------------------------------------------------\n" << std::endl;

	std::cout << std::boolalpha;
	std::cout << "Same address: " << (original == restored) << std::endl;
	if (original == restored)
		std::cout << "The original pointer was successfully recovered." << std::endl;
	else
		std::cout << "The recovered pointer does not match the original." << std::endl;
	std::cout << std::endl;
	return (0);
}
