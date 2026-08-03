/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 22:02:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/03 22:07:12 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 17:16:25 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/03 22:01:00 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat ricky("Ricky", 1);
		ShrubberyCreationForm shrubbery("tree");
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
		ShrubberyCreationForm shrubbery("garden");

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
		ShrubberyCreationForm shrubbery("park");

		signer.signForm(shrubbery);
		executor.executeForm(shrubbery);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
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
	return (0);
}
