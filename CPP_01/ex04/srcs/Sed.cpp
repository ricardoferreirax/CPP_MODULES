/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:55:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/05 14:29:32 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

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
