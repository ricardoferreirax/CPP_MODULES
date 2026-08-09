/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:55:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 22:57:15 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

#include <iostream>

int	main(void)
{
	std::cout << "\n------------------ VALID SIGN ------------------\n" << std::endl;
	try
	{
		Bureaucrat ricky("Ricky", 40);
		Form form("Form", 50, 25);
		std::cout << std::endl;

		std::cout << ricky << std::endl;
		std::cout << form << std::endl << std::endl;

		ricky.signForm(form);
		std::cout << std::endl;
		
		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n------------------ LOW GRADE ------------------\n" << std::endl;
	try
	{
		Bureaucrat	low("LowGrade", 100);
		Form form("Important Form", 50, 25);
		std::cout << std::endl;
		
		std::cout << low << std::endl;

		std::cout << form << std::endl << std::endl;

		low.signForm(form);
		std::cout << std::endl;
		
		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n------------------ INVALID FORM ------------------\n" << std::endl;
	try
	{
		Form	form("Invalid Form", 0, 50);

		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n------------------ INVALID BUREAUCRAT ------------------\n" << std::endl;
	try
	{
		Bureaucrat	invalid("Invalid", 151);

		std::cout << invalid << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return (0);
}
