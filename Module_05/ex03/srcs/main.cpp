/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:11:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/17 15:59:49 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	std::srand(std::time(NULL));

	std::cout << std::endl;
	try
	{
		Intern intern;
		Bureaucrat ricky("Ricky", 1);
		AForm *form;
		std::cout << std::endl;

		form = intern.makeForm("robotomy request", "Marvin");
		std::cout << std::endl;
		
		std::cout << *form << std::endl << std::endl;

		ricky.signForm(*form);
		ricky.executeForm(*form);
		std::cout << std::endl << std::endl;
		
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;

	try
	{
		Intern intern;
		Bureaucrat ricky("Ricky", 1);
		AForm *form;
		std::cout << std::endl;

		form = intern.makeForm("shrubbery creation", "Tree");
		std::cout << std::endl;
		
		std::cout << *form << std::endl << std::endl;

		ricky.signForm(*form);
		ricky.executeForm(*form);
		std::cout << std::endl << std::endl;
		
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;

	try
	{
		Intern intern;
		Bureaucrat ricky("Ricky", 1);
		AForm *form;
		std::cout << std::endl;

		form = intern.makeForm("presidential pardon", "Prefect");
		std::cout << std::endl;
		
		std::cout << *form << std::endl << std::endl;

		ricky.signForm(*form);
		ricky.executeForm(*form);

		std::cout << std::endl << std::endl;
		
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;

	try
	{
		Intern intern;
		AForm *form;

		std::cout << std::endl;

		form = intern.makeForm("coffee request", "Ricky");

		std::cout << *form << std::endl; // This is never executed because makeForm() throws UnknownFormException when the form name is not recognized.
		
		delete form;

	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;

	{
		Intern intern;

		// Intern creates concrete derived forms and returns them as AForm*. AForm cannot be instantiated directly because it is abstract:
		
		// AForm form; // Does not compile.
	}
	std::cout << std::endl;
	return (0);
}
