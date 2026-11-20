/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:15:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/20 21:02:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	nbrs.push_back(50);
	nbrs.push_back(60);
	std::cout << "Size: " << nbrs.size() << std::endl;
	for (it = nbrs.begin(); it != nbrs.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	it = nbrs.begin();
	std::cout << "1st: " << *it << std::endl;
	std::cout << "2nd: " << *(++it) << std::endl;
	std::cout << "3rd: " << *(++it) << std::endl;
	std::cout << "4th: " << *(++it) << std::endl;
	std::cout << "5th: " << *(++it) << std::endl;
	std::cout << "6th: " << *(++it) << std::endl;
	std::cout << std::endl;
	return (0);
}
