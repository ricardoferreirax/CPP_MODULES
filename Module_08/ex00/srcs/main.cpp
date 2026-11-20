/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:15:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/20 20:52:14 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> nbrs;
	nbrs.push_back(10);
	nbrs.push_back(20);
	nbrs.push_back(30);
	nbrs.push_back(40);
	nbrs.push_back(50);
	nbrs.push_back(60);
	std::cout << "Size: " << nbrs.size() << std::endl;
	for (size_t i = 0; i < nbrs.size(); i++)
		std::cout << nbrs[i] << std::endl;
	return (0);
}
