/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 04:45:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 23:03:06 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	std::cout << std::endl;
	try
	{
		Bureaucrat ricky("Ricky", 10);

		std::cout << ricky << std::endl;
		std::cout << std::endl;
		
		ricky.incrementGrade();
		std::cout << "After increment: " << ricky << std::endl;
		ricky.decrementGrade();
		std::cout << "After decrement: " << ricky << std::endl;
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
		Bureaucrat highest("Highest", 1);

		std::cout << highest << std::endl;
		std::cout << std::endl;
		
		highest.incrementGrade();
		std::cout << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Bureaucrat lowest("Lowest", 150);

		std::cout << lowest << std::endl;
		std::cout << std::endl;

		lowest.decrementGrade();
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
		Bureaucrat invalid("Invalid", 151);

		std::cout << invalid << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << std::endl;

	return (0);
}
