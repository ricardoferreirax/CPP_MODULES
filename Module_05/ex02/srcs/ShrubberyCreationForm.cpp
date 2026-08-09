/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 17:42:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 21:00:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation Form", 145, 137), _target("Somewhere")
{
	std::cout << "[Shrubbery] A planting request has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "[Shrubbery] A planting request has been created for " << this->_target << "!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "[Shrubbery] Planting request copied for " << this->_target << "!" << std::endl;
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
	std::cout << "[Shrubbery] " << this->_target << " has been destroyed!" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::drawTree(std::ostream &out) const
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
	out << "  ******/***\\__\\****" << std::endl;
}

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
