/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:47:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/11 18:08:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

#include <iostream>

int	main(void)
{
	Array<int> empty;

	Array<int>	numbers(4);

	std::cout << std::endl;

	numbers[0] = 10;
	numbers[1] = 20;
	numbers[2] = 30;
	numbers[3] = 40;

	std::cout << "Values: ";
	for (unsigned int i = 0; i < 4; i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl << std::endl;

	Array<int>	copy(numbers);

	std::cout << std::endl;

	std::cout << "Original: " << std::endl;
	for (unsigned int i = 0; i < 4; i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Copy:     ";
	for (unsigned int i = 0; i < 4; i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl << std::endl;

	// deep copy
	copy[0] = 999;

	std::cout << "Original[0]: " << numbers[0] << std::endl;
	std::cout << "Copy[0]:     " << copy[0] << std::endl << std::endl;

	Array<int>	assigned;
	
	std::cout << std::endl;

	assigned = numbers;

	std::cout << "Assigned: ";
	for (unsigned int i = 0; i < 4; i++)
		std::cout << assigned[i] << " ";
	std::cout << std::endl << std::endl;

	try
	{
		std::cout << numbers[4] << std::endl;
		std::cout << numbers[100] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return (0);
}
