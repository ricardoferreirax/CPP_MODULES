/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:03:39 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/07 18:19:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

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
	std::cout << "[Intern] Assignment completed!" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "[Intern] Intern has been destroyed!" << std::endl;
}

AForm *Intern::makeForm(const std::string formName, const std::string &target)
{
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int	i;

	i = 0;
	while (i < 3 && forms[i] != formName)
		i++;
	switch (i)
	{
		case 0:
			std::cout << "[Intern] Preparing a Presidential Pardon form!" << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "[Intern] Preparing a Robotomy Request form!" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "[Intern] Preparing a Shrubbery Creation form!" << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			throw UnknownFormException();
	}
}

const char *Intern::UnknownFormException::what(void) const throw()
{
	return ("Unknown form requested!");
}
