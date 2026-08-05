/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:58:22 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/05 18:50:07 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void)
{
	std::cout << "[Intern] An intern has been created!" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "[Intern] An intern has been copied!" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "[Intern] Nothing needed to be assigned!" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "[Intern] The intern has been destroyed!" << std::endl;
}

AForm *Intern::createShrubbery(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	typedef AForm *(Intern::*FormCreator)(const std::string &) const;

	const std::string formNames[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential request"
	};

	FormCreator creators[3] = 
	{
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates \"" << formName << "\" for " << target << "!" << std::endl;
			return ((this->*creators[i])(target));
		}
	}
	throw UnknownFormException();
}

const char *Intern::UnknownFormException::what(void) const throw()
{
	return ("The intern does not know how to create that form!");
}
