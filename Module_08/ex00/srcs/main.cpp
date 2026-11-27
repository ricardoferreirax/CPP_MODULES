/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:15:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/27 13:08:09 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
// #include <algorithm>

int	main(void)
{
	std::vector<int> nbrs;
	std::vector<int>::iterator it;
	std::list<int> lst;
	std::list<int>::iterator lst_it;
	
	nbrs.push_back(10);
	nbrs.push_back(20);
	nbrs.push_back(30);
	nbrs.push_back(20);
	std::cout << "vector: ";
	for (it = nbrs.begin(); it != nbrs.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "vector size: " << nbrs.size() << std::endl << std::endl;
	// it = std::find(nbrs.begin(), nbrs.end(), 20);
	// if (it != nbrs.end())
	//	std::cout << "found " << *it << " in vector at index " << (it - nbrs.begin()) << std::endl;
	// else
	// 	std::cout << "value not found" << std::endl << std::endl;
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(35);
	lst.push_back(15);
	std::cout << "list: ";
	for (lst_it = lst.begin(); lst_it != lst.end(); lst_it++)
		std::cout << *lst_it << " ";
	std::cout << std::endl;
	std::cout << "list size: " << lst.size() << std::endl << std::endl;
	// lst_it = std::find(lst.begin(), lst.end(), 15);
	// if (lst_it != lst.end())
	// 	std::cout << "found " << *lst_it << " in list " << std::endl << std::endl;
	// else
	// 	std::cout << "value not found" << std::endl << std::endl;
	try
	{
		it = easyfind(nbrs, 20);
		std::cout << "found " << *it << " in vector at index " << (it - nbrs.begin()) << std::endl;
		lst_it = easyfind(lst, 15);
		std::cout << "found " << *lst_it << " in list " << std::endl;
		lst_it = easyfind(lst, 45);
		std::cout << "found " << *lst_it << " in list " << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	try
	{
		lst_it = easyfind(lst, 35);
		std::cout << "found " << *lst_it << " in list " << std::endl;
		it = easyfind(nbrs, 100);
		std::cout << "found " << *it << " in vector " << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
