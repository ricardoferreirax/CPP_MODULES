/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:42:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/17 15:45:38 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

// Builds the AForm base part with the fixed requirements of a ShrubberyCreationForm: sign grade = 145 and execute grade = 137.
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation Form", 145, 137), _target("Somewhere")
{
	std::cout << "[Shrubbery] A planting request has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "[Shrubbery] A planting request has been created for " << this->_target << "!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "[Shrubbery] Planting request copied for " << this->_target << "!" << std::endl;
}

//  Calls AForm::operator=() to copy the assignable base-class state, then copies the target of the ShrubberyCreationForm.
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << "[Shrubbery] Request data has been assigned!" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "[Shrubbery] " << this->_target << " has been destroyed!" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

//  Writes the ASCII tree into the provided output stream. In processForm(), an std::ofstream is passed to this function, so the tree
// is written into the target file. The function is const because drawing the tree does not modify the ShrubberyCreationForm object.
void ShrubberyCreationForm::drawTree(std::ostream &out) const
{
	out << "    oxoxoo    ooxoo" << std::endl;
	out << "  ooxoxo oo  oxoxooo" << std::endl;
	out << " oooo xxoxoo ooo ooox" << std::endl;
	out << " oxo o oxoxo  xoxxoxo" << std::endl;
	out << "  oxo xooxoooo o ooo" << std::endl;
	out << "    ooooooooo  oooo" << std::endl;
	out << "        oo  ooo o" << std::endl;
	out << "         |  /" << std::endl;
	out << "         |  |" << std::endl;
	out << "         |  |" << std::endl;
	out << "         |  |" << std::endl;
	out << "         |  |" << std::endl;
	out << "  ********************" << std::endl;
}

// Performs the concrete action of a ShrubberyCreationForm. The output filename is created from the target: <target>_shrubbery.
// std::ofstream opens that file for writing. If the file cannot be opened, OutputFileException is thrown.
// If the file opens successfully, drawTree() writes the ASCII tree into it. The file is automatically closed when the local std::ofstream 
// object reaches the end of its scope. This function implements AForm's virtual processForm() operation. It is called polymorphically by 
// AForm::execute() after the signing and grade checks have succeeded.
void ShrubberyCreationForm::processForm(void) const
{
	std::string	fileName;

	fileName = this->_target + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (!file)
		throw OutputFileException();
	this->drawTree(file);
	std::cout << "[Shrubbery] Trees were planted in " << fileName << "!" << std::endl;
}

const char *ShrubberyCreationForm::OutputFileException::what(void) const throw()
{
	return ("The shrubbery file could not be created!");
}
