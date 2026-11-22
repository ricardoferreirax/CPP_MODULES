/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:15:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/22 23:04:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	std::vector<int> nbrs;
	std::vector<int>::iterator it;
	
	nbrs.push_back(10);
	nbrs.push_back(20);
	nbrs.push_back(30);
	nbrs.push_back(40);
	nbrs.push_back(30);
	std::cout << "Size: " << nbrs.size() << std::endl;
	for (it = nbrs.begin(); it != nbrs.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	it = std::find(nbrs.begin(), nbrs.end(), 20);
	std::cout << "F: " << *it << " at index " << (it - nbrs.begin()) << std::endl;
	it = std::find(nbrs.begin(), nbrs.end(), 30);
	std::cout << "F: " << *it << " at index " << (it - nbrs.begin()) << std::endl;
	it = std::find(nbrs.begin(), nbrs.end(), 100);
	std::cout << "NF: " << *it << std::endl << std::endl;
	easyfind(nbrs, 20);
	easyfind(nbrs, 30);
	easyfind(nbrs, 100);
	return (0);
}
