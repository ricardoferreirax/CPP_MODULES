/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:55:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/05 22:26:11 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"
#include <fstream>

Sed::Sed(char *inputFilename, char *searchString, char *replaceString)
	: _searchString(searchString), _replaceString(replaceString), _inputFilename(inputFilename)
{
	this->_outputFilename = this->_inputFilename + ".replace";
	std::cout << "Sed initialized for file: " << this->_inputFilename << std::endl;
}

const std::string& Sed::getSearchString(void) const
{
	return (this->_searchString);
}

const std::string& Sed::getReplaceString(void) const
{
	return (this->_replaceString);
}

const std::string& Sed::getInputFilename(void) const
{
	return (this->_inputFilename);
}

const std::string& Sed::getOutputFilename(void) const
{
	return (this->_outputFilename);
}

// process file content (read + replace + write)
void Sed::processFile(void) const
{
	std::ifstream inputFile(this->getInputFilename().c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: cannot open file '" << this->getInputFilename() << "'" << std::endl;
		return ;
	}
	std::ofstream outputFile(this->getOutputFilename().c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: cannot create file '" << this->getOutputFilename() << "'" << std::endl;
		inputFile.close();
		return ;
	}
	std::string line;
	std::string::size_type pos;
	while (std::getline(inputFile, line))
	{
		pos = 0;
		while ((pos = line.find(this->getSearchString(), pos)) != std::string::npos)
		{
			line.erase(pos, this->getSearchString().length());
			line.insert(pos, this->getReplaceString());
			pos += this->getReplaceString().length();
		}
		outputFile << line;
		if (!inputFile.eof())
			outputFile << std::endl;
	}
	inputFile.close();
	outputFile.close();
}
