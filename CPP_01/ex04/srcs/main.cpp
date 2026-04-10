/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:07:53 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/10 14:01:04 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"
#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::string		fileName;
	std::string		toReplace;
	std::string		replaceBy;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (ac != 4)
		return (std::cerr << "Invalid Number of Arguments!\nUsage: ./Sed_is_for_losers <file> <s1> <s2>\n", 1);

	fileName = av[1];
	toReplace = av[2];
	replaceBy = av[3];

	if (toReplace.empty())
		return (std::cerr << "Error: s1 cannot be empty\n", 1);

	infile.open(fileName.c_str());
	if (!infile.is_open())
		return (std::cerr << "Error: cannot open input file\n", 1);
	infile.close();

	outfile.open((fileName + ".replace").c_str());
	if (!outfile.is_open())
		return (std::cerr << "Error: cannot create output file\n", 1);
	outfile.close();

	Sed sed(fileName, toReplace, replaceBy);
	sed.processFile();

	return (0);
}
