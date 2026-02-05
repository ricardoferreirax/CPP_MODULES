/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:55:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/05 23:04:19 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"
#include <fstream>

Sed::Sed(const char *filename, const char *s1, const char *s2) : _filename(filename), _s1(s1), _s2(s2)
{
	this->_outputFilename = this->_filename + ".replace";
	std::cout << "Sed initialized for file: " << this->_filename << std::endl;
}

const std::string& Sed::getFilename(void) const
{
	return (this->_filename);
}

const std::string& Sed::getS1(void) const
{
	return (this->_s1);
}

const std::string& Sed::getS2(void) const
{
	return (this->_s2);
}

const std::string& Sed::getOutputFilename(void) const
{
	return (this->_outputFilename);
}

int Sed::processFile(void) const
{
	std::ifstream inputFile(this->_filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: cannot open file '" << this->_filename << "'" << std::endl;
		return (1);
	}
	std::ofstream outputFile(this->_outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: cannot create file '" << this->_outputFilename << "'" << std::endl;
		inputFile.close();
		return (1);
	}
	std::string line;
	std::string::size_type pos;
	while (std::getline(inputFile, line))
	{
		pos = 0;
		while ((pos = line.find(this->_s1, pos)) != std::string::npos)
		{
			line.erase(pos, this->_s1.length());
			line.insert(pos, this->_s2);
			pos += this->_s2.length();
		}
		outputFile << line;
		if (!inputFile.eof())
			outputFile << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}
