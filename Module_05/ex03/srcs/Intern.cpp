/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:39:31 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 22:41:22 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

#include <iostream>

Intern::Intern(void)
{
	std::cout << "[Intern] Intern has been created!" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "[Intern] Intern has been copied!" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "[Intern] Intern assignment completed!" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "[Intern] Intern has been destroyed!" << std::endl;
}

const char *Intern::UnknownFormException::what(void) const throw()
{
	return ("The intern does not recognize this form.");
}

AForm *Intern::makeForm(const std::string formName, const std::string &target)
{
	std::string	forms[3];
	int	i;

	forms[0] = "presidential pardon";
	forms[1] = "robotomy request";
	forms[2] = "shrubbery creation";
	i = 0;
	while (i < 3 && forms[i] != formName)
		i++;
	switch (i)
	{
		case 0:
			std::cout << "[Intern] Preparing a Presidential Pardon Form for " << target << "." << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "[Intern] Preparing a Robotomy Request Form for " << target << "." << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "[Intern] Preparing a Shrubbery Creation Form for " << target << "." << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			throw UnknownFormException();
	}
}
