/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:07:53 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/05 23:03:29 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Run: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 should not be empty" << std::endl;
		return (1);
	}
	Sed sed(filename.c_str(), s1.c_str(), s2.c_str());
	if (sed.processFile() != 0)
	{
		std::cerr << "Error: could not process file" << std::endl;
		return (1);
	}
	std::cout << "Done: created " << sed.getOutputFilename() << std::endl;
	return (0);
}
