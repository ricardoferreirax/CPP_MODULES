/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:10:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/08 19:55:18 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>

int	main(void)
{
	Data data("Ricardo", 24);
	Data *original;
	// Data *res;
	uintptr_t raw;

	original = &data;
	
	std::cout << "Name: " << original->getName() << " | Age: " << original->getAge() << std::endl;
	std::cout << "Original pointer: " << original << std::endl;
	raw = Serializer::serialize(original);
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << std::endl;

	// result = Serializer::deserialize(raw);
	// std::cout << "Deserialized pointer: " << res << std::endl;
	// std::cout << "Name: " << res->getName() << std::endl;
	// std::cout << "Age: " << res->getAge() << std::endl;
	// std::cout << std::endl;

	// if (original == res)
	// 	std::cout << "Pointers are equal!" << std::endl;
	// else
	// 	std::cout << "Pointers are different!" << std::endl;

	return (0);
}

// int	main(void)
// {
// 	Data data;
// 	Data *ptr;
// 	uintptr_t raw;

// 	data.name = "Ricky";
// 	data.age = 25;
// 	data.score = 42.5;

// 	ptr = &data;

// 	std::cout << "Original pointer : " << ptr << std::endl;
// 	raw = Serializer::serialize(ptr);
// 	std::cout << "Serialized value : " << raw << std::endl;

// 	return (0);
// }
