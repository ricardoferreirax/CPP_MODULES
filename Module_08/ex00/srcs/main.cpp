/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:15:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/22 23:16:06 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> nbrs;
	std::vector<int>::iterator it;
	
	nbrs.push_back(10);
	nbrs.push_back(20);
	nbrs.push_back(30);
	nbrs.push_back(40);
	nbrs.push_back(30);
	std::cout << "Size: " << nbrs.size() << std::endl << std::endl;
	for (it = nbrs.begin(); it != nbrs.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	it = std::find(nbrs.begin(), nbrs.end(), 20);
	if (it != nbrs.end())
		std::cout << "F: " << *it << " at index " << (it - nbrs.begin()) << std::endl;
	it = std::find(nbrs.begin(), nbrs.end(), 30);
	if (it != nbrs.end())
		std::cout << "F: " << *it << " at index " << (it - nbrs.begin()) << std::endl;
	it = std::find(nbrs.begin(), nbrs.end(), 100);
	if (it != nbrs.end())
		std::cout << "F: " << *it << std::endl;
	else
		std::cout << "NF: Value not found" << std::endl;
	std::cout << std::endl;
	try
	{
		it = easyfind(nbrs, 20);
		std::cout << "F: " << *it << " at index " << (it - nbrs.begin()) << std::endl;
		it = easyfind(nbrs, 30);
		std::cout << "F: " << *it << " at index " << (it - nbrs.begin()) << std::endl;
		it = easyfind(nbrs, 100);
		std::cout << "NF: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
