/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:11:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 22:36:21 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	std::srand(std::time(NULL));
	std::cout << "\n------------------ SHRUBBERY ----------------------\n" << std::endl;
	try
	{
		Bureaucrat ricky("Ricky", 1);
		ShrubberyCreationForm shrubbery("Tree");
		std::cout << std::endl;

		std::cout << ricky << std::endl;
		std::cout << shrubbery << std::endl << std::endl;

		ricky.executeForm(shrubbery);
		ricky.signForm(shrubbery);
		ricky.executeForm(shrubbery);
		std::cout << shrubbery << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n------------------ ROBOTOMY ----------------------\n" << std::endl << std::endl;

	try
	{
		Bureaucrat ricky("Ricky", 1);
		RobotomyRequestForm	robotomy("Marvin");
		std::cout << std::endl;
		
		std::cout << ricky << std::endl;
		std::cout << robotomy << std::endl << std::endl;

		ricky.signForm(robotomy);
		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			ricky.executeForm(robotomy);
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n------------------ PARDON ----------------------\n" << std::endl << std::endl;

	try
	{
		Bureaucrat ricky("Ricky", 1);
		PresidentialPardonForm pardon("Prefect");
		std	::cout << std::endl;
		
		std::cout << ricky << std::endl;
		std::cout << pardon << std::endl << std::endl;
		
		ricky.signForm(pardon);
		ricky.executeForm(pardon);
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n------------------ LOW GRADE ----------------------\n" << std::endl;

	try
	{
		Bureaucrat low("LowGrade", 150);
		PresidentialPardonForm pardon("Prefect");
		std::cout << std::endl;
		
		low.signForm(pardon);
		low.executeForm(pardon);
		std	::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n------------------ UNSIGNED FORM ----------------------\n" << std::endl;
	try
	{
		Bureaucrat ricky("Ricky", 1);
		ShrubberyCreationForm shrubbery("Tree");
		std::cout << std::endl;

		std::cout << ricky << std::endl;
		std::cout << shrubbery << std::endl << std::endl;

		ricky.executeForm(shrubbery);
		std::cout << shrubbery << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
