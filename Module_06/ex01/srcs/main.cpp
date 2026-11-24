/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:10:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/24 10:06:30 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

// if "original" points to a Data object called car->serialize() converts address stored in original into a uintptr_t called raw.
// deserialize(raw) converts that int representation back into a Data pointer called restored.
// no new car is created during this process and original car is never copied.
// both original and restored should contain the address of the same object.
// if serialization/deserialization worked correctly->comparison (original == restored) is true.
// pointer comparison in this case compares addresses stored by two pointers->it doesnt compare brand,year or price.
// result is true cause both pointers refer to exact same Data object in memory.
// this also explains why we can access restored->brand, restored->year and restored->price after deserialization.
// deserialize() didnt recreate these values->restored simply points back to original Data object where those values already exist.

int main(int ac, char **av)
{
	Data		car;
	Data		otherCar;
	Data		*original;
	Data		*restored;
	Data		*ptr;
	uintptr_t	raw;

	(void)av;
	if (ac != 1)
	{
		std::cerr << "Use: ./Serialize" << std::endl;
		return (1);
	}
	car.brand = "Porsche";
	car.year = 2024;
	car.price = 135000;
	original = &car;
	std::cout << "\n--- original pointer ---\n" << std::endl;
	std::cout << "brand: " << car.brand << std::endl;
	std::cout << "year: " << car.year << std::endl;
	std::cout << "price: " << car.price << " EUR" << std::endl;
	std::cout << "\n--- serialization ---\n" << std::endl;
	std::cout << "original address: " << original << std::endl;
	raw = Serializer::serialize(original);
	std::cout << "serialized address: " << raw << std::endl;
	restored = Serializer::deserialize(raw);
	std::cout << "restored address: " << restored << std::endl;
	std::cout << "\n--- restored data ---\n" << std::endl;
	std::cout << "brand: " << restored->brand << std::endl;
	std::cout << "year: " << restored->year << std::endl;
	std::cout << "price: " << restored->price << " EUR" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "same address: " << (original == restored) << std::endl;
	if (original == restored)
		std::cout << "original pointer was successfully recovered." << std::endl;
	else
		std::cout << "recovered pointer does not match original." << std::endl;
	std::cout << "\n--- serialize and deserialize a NULL pointer ---\n" << std::endl;
	ptr = NULL;
	raw = Serializer::serialize(ptr);
	restored = Serializer::deserialize(raw);
	std::cout << "original address: " << ptr << std::endl;
	std::cout << "restored address: " << restored << std::endl;
	std::cout << "same address: " << (ptr == restored) << std::endl;
	std::cout << "\n--- compare pointers to two different Data objects ---\n" << std::endl;
	otherCar.brand = "Ferrari";
	otherCar.year = 2025;
	otherCar.price = 250000;
	ptr = &otherCar;
	raw = Serializer::serialize(ptr);
	restored = Serializer::deserialize(raw);
	std::cout << "original car address: " << original << std::endl;
	std::cout << "other car address: " << restored << std::endl;
	std::cout << "same address: " << (original == restored) << std::endl;
	std::cout << "serialization successful: " << (ptr == restored) << std::endl;
	if (original == restored)
		std::cout << "pointers match." << std::endl;
	else
		std::cout << "pointers do not match." << std::endl;
	std::cout << std::endl;
	return (0);
}
