/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:07:53 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/05 14:25:08 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Run: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	Sed sed(av[1], av[2], av[3]);
	std::cout << "Input:  " << sed.getInputFilename() << std::endl;
	std::cout << "Output: " << sed.getOutputFilename() << std::endl;
	std::cout << "s1:     " << sed.getSearchString() << std::endl;
	std::cout << "s2:     " << sed.getReplaceString() << std::endl;

	return 0;
}
