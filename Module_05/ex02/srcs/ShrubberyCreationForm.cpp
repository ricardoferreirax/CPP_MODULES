/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:06:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/05 11:02:49 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void) 
	: AForm("Shrubbery request", 145, 137), _target("Somewhere")
{
	std::cout << "[Shrubbery] A request has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("Shrubbery request", 145, 137), _target(target)
{
	std::cout << "[Shrubbery] A request has been created for " << this->_target << "!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "[Shrubbery] Copied the planting request for " << this->_target << "!" << std::endl;
}

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
	std::cout << "[Shrubbery] The request for " << this->_target << " has been destroyed!" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::writeTree(std::ostream &out) const
{
	out << "    oxoxoo    ooxoo" << std::endl;
	out << "  ooxoxo oo  oxoxooo" << std::endl;
	out << " oooo xxoxoo ooo ooox" << std::endl;
	out << " oxo o oxoxo  xoxxoxo" << std::endl;
	out << "  oxo xooxoooo o ooo" << std::endl;
	out << "    ooo\\oo\\  /o/o" << std::endl;
	out << "        \\  \\/ /" << std::endl;
	out << "         |   /" << std::endl;
	out << "         |  |" << std::endl;
	out << "         | D|" << std::endl;
	out << "         |  |" << std::endl;
	out << "         |  |" << std::endl;
	out << "  ______/____\\____" << std::endl;
}

void ShrubberyCreationForm::performAction(void) const
{
	const std::string fileName = this->_target + "_shrubbery";
	std::ofstream file(fileName.c_str());

	if (!file)
		throw OutputFileException();
	this->writeTree(file);
	if (!file.good())
		throw OutputFileException();
	file.close();
	std::cout << "[Shrubbery] Trees were planted in " << fileName << "!" << std::endl;
}

const char *ShrubberyCreationForm::OutputFileException::what(void) const throw()
{
	return ("The shrubbery file could not be written!");
}
