/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:53:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/14 12:32:03 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	try
	{
		PmergeMe	pmerge;
		
		pmerge.validate_input(ac, av);
		pmerge.print_nbrs();
		pmerge.sort_nbrs();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	std::cout << std::endl;
	return (0);
}
