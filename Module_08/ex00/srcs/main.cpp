/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:15:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/20 21:10:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	it = std::find(nbrs.begin(), nbrs.end(), 30);
	std::cout << "Found: " << *it << " at index " << (it - nbrs.begin()) << std::endl;
	it = std::find(nbrs.begin(), nbrs.end(), 100);
	std::cout << "Not Found: " << *it << std::endl;
	return (0);
}
