/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:58:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/05 10:58:21 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));
	std::cout << std::endl;
	
	try
	{
		Bureaucrat ricky("Ricky", 1);
		ShrubberyCreationForm shrubbery("Tree");
		AForm &form = shrubbery;

		std::cout << ricky << std::endl;
		std::cout << form << std::endl;

		ricky.executeForm(form);
		ricky.signForm(form);
		ricky.executeForm(form);

		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat low("LowGrade", 150);
		ShrubberyCreationForm shrubbery("Tree");

		std::cout << low << std::endl;
		std::cout << shrubbery << std::endl;

		low.signForm(shrubbery);
		low.executeForm(shrubbery);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat signer("Signer", 145);
		Bureaucrat executor("Executor", 137);
		ShrubberyCreationForm shrubbery("Tree");

		signer.signForm(shrubbery);
		executor.executeForm(shrubbery);
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
		Bureaucrat ricky("Ricky", 1);
		RobotomyRequestForm	robotomy("Marvin");
		AForm &form = robotomy;

		std::cout << ricky << std::endl;
		std::cout << form << std::endl;

		ricky.executeForm(form);
		ricky.signForm(form);

		for (int i = 0; i < 5; i++)
			ricky.executeForm(form);

		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Bureaucrat low("LowGrade", 150);
		RobotomyRequestForm	robotomy("Marvin");

		std::cout << low << std::endl;
		std::cout << robotomy << std::endl;

		low.signForm(robotomy);
		low.executeForm(robotomy);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat signer("Signer", 72);
		Bureaucrat executor("Executor", 45);
		RobotomyRequestForm	robotomy("Marvin");

		signer.signForm(robotomy);
		executor.executeForm(robotomy);
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
		Bureaucrat ricky("Ricky", 1);
		PresidentialPardonForm pardon("Prefect");
		AForm &form = pardon;

		std::cout << ricky << std::endl;
		std::cout << form << std::endl;

		ricky.executeForm(form);
		ricky.signForm(form);
		ricky.executeForm(form);

		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat low("LowGrade", 150);
		PresidentialPardonForm pardon("Prefect");

		std::cout << low << std::endl;
		std::cout << pardon << std::endl;

		low.signForm(pardon);
		low.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat signer("Signer", 25);
		Bureaucrat executor("Executor", 5);
		PresidentialPardonForm pardon("Prefect");

		signer.signForm(pardon);
		executor.executeForm(pardon);
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
		Bureaucrat invalid("Invalid", 151);

		std::cout << invalid << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	return (0);
}
