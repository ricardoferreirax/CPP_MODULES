/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:17:52 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/06 22:21:46 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"
#include <fstream>

Sed::Sed(const std::string &fileName, const std::string &toReplace,
	const std::string &replaceBy)
{
	this->_fileName = fileName;
	this->_toReplace = toReplace;
	this->_replaceBy = replaceBy;
}

std::string	Sed::replaceLine(std::string line) const
{
	std::size_t	found;

	found = line.find(_toReplace);
	while (found != std::string::npos)
	{
		line.erase(found, _toReplace.length());
		line.insert(found, _replaceBy);
		found = line.find(_toReplace, found + _replaceBy.length());
	}
	return (line);
}

void	Sed::processFile(void) const
{
	std::ifstream infile(_fileName.c_str());
	std::ofstream outfile((_fileName + ".replace").c_str());
	
	std::string	line;

	while (std::getline(infile, line))
	{
		outfile << replaceLine(line);
		if (!infile.eof())
			outfile << "\n";
	}
	infile.close();
	outfile.close();
}
