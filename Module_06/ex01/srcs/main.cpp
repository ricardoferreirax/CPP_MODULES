/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:10:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/20 15:14:28 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

#include <iostream>

int	main(void)
{
	Data *original;
	Data *restored;
	Data car;
	uintptr_t raw;

	car.brand = "Porsche";
	car.year = 2024;
	car.price = 135000;

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
		std::cout << "Success: pointers are equal." << std::endl;
	else
		std::cout << "Error: pointers are different." << std::endl;
	std::cout << std::endl;
	return (0);
}
