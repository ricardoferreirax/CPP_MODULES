/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:40:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/05 16:03:08 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main(void)
{
	std::cout << std::endl;
	try
	{
		Bureaucrat	ricky("Ricky", 10);
		Form		form("Contract", 20, 30);

		std::cout << std::endl;
		
		std::cout << ricky << std::endl;
		std::cout << form << std::endl;
		std::cout << std::endl;
		
		ricky.signForm(form);
		std::cout << std::endl;
		
		std::cout << form << std::endl;
		std::cout << std::endl;
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
		Bureaucrat	low("LowGrade", 100);
		Form		form("Contract", 50, 40);

		std::cout << std::endl;
		
		std::cout << low << std::endl;
		std::cout << form << std::endl;
		std::cout << std::endl;

		low.signForm(form);
		std::cout << std::endl;

		std::cout << form << std::endl;
		std::cout << std::endl;
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
		Bureaucrat	exact("Exact signer", 50);
		Form		form("Contract", 50, 40);

		std::cout << std::endl;

		exact.signForm(form);
		std::cout << std::endl;

		std::cout << form << std::endl;
		std::cout << std::endl;
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
		Form invalidHigh("Invalid high", 0, 50);

		std::cout << invalidHigh << std::endl;
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
		Form invalidLow("Invalid low", 151, 50);

		std::cout << invalidLow << std::endl;
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
		Bureaucrat signer("Signer", 1);
		Form original("Contract", 25, 5);

		std::cout << std::endl;

		signer.signForm(original);
		std::cout << std::endl;

		Form copy(original);
		Form assigned("Assigned", 100, 100);

		std::cout << std::endl;

		assigned = original;

		std::cout << original << std::endl;
		std::cout << copy << std::endl;
		std::cout << assigned << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	return (0);
}