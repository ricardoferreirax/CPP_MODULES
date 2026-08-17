/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:39:31 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/17 15:54:56 by rmedeiro         ###   ########.fr       */
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

// Creates and returns the type of form requested by its name. makeForm() receives:
//     formName -> identifies which concrete form must be created.
//     target   -> target that will be passed to that form's constructor.
// The Intern does not return a PresidentialPardonForm*,RobotomyRequestForm* or ShrubberyCreationForm* directly.
// Instead, it returns: AForm *. This is possible because all three concrete forms inherit from AForm.
// Therefore, a base-class pointer can point to any of the derived objects: AForm *form = new RobotomyRequestForm(target);
// Here, the pointer type is AForm*, but the real allocated object is a RobotomyRequestForm. The array contains all valid form
// names. The while loop searches for the requested name and stops when it finds a match or reaches the end.
// Each form is dynamically allocated with new because the object must remain alive after makeForm() returns.
// If no valid form name is found, i becomes 3 and the default case throws UnknownFormException.
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
