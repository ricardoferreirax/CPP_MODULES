/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:15:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/22 23:34:22 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int	main(void)
{
	std::vector<int> nbrs;
	std::vector<int>::iterator it;
	std::list<int> lst;
	std::list<int>::iterator lst_it;
	nbrs.push_back(10);
	nbrs.push_back(20);
	nbrs.push_back(30);
	std::cout << "Vector size: " << nbrs.size() << std::endl << std::endl;
	for (it = nbrs.begin(); it != nbrs.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	it = std::find(nbrs.begin(), nbrs.end(), 20);
	if (it != nbrs.end())
		std::cout << "F: " << *it << " at index " << (it
			- nbrs.begin()) << std::endl;
	it = std::find(nbrs.begin(), nbrs.end(), 30);
	if (it != nbrs.end())
		std::cout << "F: " << *it << " at index " << (it
			- nbrs.begin()) << std::endl;
	it = std::find(nbrs.begin(), nbrs.end(), 100);
	if (it != nbrs.end())
		std::cout << "F: " << *it << std::endl;
	else
		std::cout << "NF: Value not found" << std::endl;
	std::cout << std::endl;
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(35);
	std::cout << "List size: " << lst.size() << std::endl << std::endl;
	try
	{
		it = easyfind(nbrs, 20);
		std::cout << "F: " << *it << " at index " << (it - nbrs.begin()) << std::endl;
		it = easyfind(nbrs, 30);
		std::cout << "F: " << *it << " at index " << (it - nbrs.begin()) << std::endl;
		lst_it = easyfind(lst, 25);
		std::cout << "F: " << *lst_it << std::endl;
		lst_it = easyfind(lst, 45);
		std::cout << "F: " << *lst_it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		std::cout << std::endl;
	}
	try
	{
		lst_it = easyfind(lst, 35);
		std::cout << "F: " << *lst_it << std::endl;
		it = easyfind(nbrs, 100);
		std::cout << "F: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
