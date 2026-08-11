/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:47:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/11 18:51:28 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

#include <iostream>
#include <string>

int	main(void)
{
	Array<int> defaultArray;
	Array<int> nbrs(4);

	std::cout << std::endl;
	std::cout << "Default size: " << defaultArray.size() << std::endl << std::endl;

	nbrs[0] = 10;
	nbrs[1] = 20;
	nbrs[2] = 30;
	nbrs[3] = 40;

	std::cout << "Values: ";
	for (unsigned int i = 0; i < nbrs.size(); i++)
		std::cout << nbrs[i] << " ";
	std::cout << std::endl << std::endl;

	Array<int> copy(nbrs);

	std::cout << std::endl;

	std::cout << "Copy: ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl << std::endl;

	try
	{
		std::cout << nbrs[4] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << defaultArray[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	const Array<int> constNbrs(nbrs);

	std::cout << std::endl;

	std::cout << "Const values: ";
	for (unsigned int i = 0; i < constNbrs.size(); i++)
		std::cout << constNbrs[i] << " ";
	std::cout << std::endl << std::endl;

	// constNbrs[0] = 100;

	return (0);
}
