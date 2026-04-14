/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:17:52 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/14 13:54:53 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"
#include <fstream>

// Constructor initializes the Sed object with the provided file name, the string 
// to replace, and the string to replace it with.
Sed::Sed(const std::string &fileName, const std::string &toReplace,
	const std::string &replaceBy)
{
	this->_fileName = fileName;
	this->_toReplace = toReplace;
	this->_replaceBy = replaceBy;
}

// Takes a line of text and replaces all occurrences of the _toReplace string 
// with the _replaceBy string. It returns the modified line.
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

// Reads the content of the file specified by _fileName, processes each line  using the replaceLine.
// It writes the modified lines to a new file with the same name but with .replace.
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
