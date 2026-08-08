/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:10:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/08 20:30:34 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>

int	main(void)
{
	Data data("Ricardo", 24);
	Data *original;
	Data *res;
	uintptr_t raw;

	original = &data;
	res = NULL;

	std::cout << "Original data: " << original->getName() << " | Age: " << original->getAge() << std::endl;
	std::cout << std::endl;

	std::cout << ">>>> Before deserialize <<<<<" << std::endl << std::endl;
	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Restored pointer: " << res << std::endl;
	std::cout << "Are pointers equal? " << (original == res) << std::endl << std::endl;

	raw = Serializer::serialize(original);
	std::cout << "Serialized value: " << raw << std::endl << std::endl;

	res = Serializer::deserialize(raw);
	std::cout << ">>>> After deserialize <<<<<" << std::endl << std::endl;
	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Restored pointer: " << res << std::endl;
	std::cout << "Are pointers equal? " << (original == res) << std::endl << std::endl;

	std::cout << "Restored data: " << res->getName() << " | Age: " << res->getAge() << std::endl << std::endl;

	return (0);
}
