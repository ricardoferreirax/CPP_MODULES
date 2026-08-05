/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:10:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/05 18:53:21 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include <cstdlib>
#include <ctime>

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

		form = intern.makeForm("shrubbery creation", "Tree");

		std::cout << *form << std::endl;

		std::cout << std::endl;

		ricky.executeForm(*form);
		ricky.signForm(*form);
		ricky.executeForm(*form);

		std::cout << std::endl;

		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	try
	{
		Intern intern;
		Bureaucrat ricky("Ricky", 1);
		AForm *form;

		std::cout << std::endl;

		form = intern.makeForm("robotomy request", "Bender");

		std::cout << *form << std::endl;

		std::cout << std::endl;

		ricky.signForm(*form);

		std::cout << std::endl;

		for (int i = 0; i < 5; i++)
			ricky.executeForm(*form);

		std::cout << std::endl;

		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		Intern intern;
		Bureaucrat president("President", 1);
		AForm *form;

		std::cout << std::endl;

		form = intern.makeForm("presidential request", "Prefect");

		std::cout << std::endl;

		std::cout << *form << std::endl;

		std::cout << std::endl;

		president.signForm(*form);
		president.executeForm(*form);

		std::cout << std::endl;

		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		Intern	intern;
		AForm	*form;

		std::cout << std::endl;

		form = intern.makeForm("coffee request", "Ricky");

		std::cout << std::endl;

		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
