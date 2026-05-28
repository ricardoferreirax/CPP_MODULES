/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 04:45:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/28 23:00:39 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Ricky", 2);
		std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
		std::cout << std::endl;
		
		Bureaucrat b(a);
		std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
		std::cout << std::endl;
		
		Bureaucrat c("Default", 150);
		std::cout << "Before assignment: " << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
		c = a;
		std::cout << "After assignment: " << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
		std::cout << std::endl;
		
		a.incrementGrade();
		std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
		std::cout << std::endl;
		
		c.decrementGrade();
		std::cout << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "\nException: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------------------------------------------------------------------" << std::endl;

	try
	{
		Bureaucrat high("TooHigh", 0);
		std::cout << high << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat low("TooLow", 151);
		std::cout << low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
		std::cout << top << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
		std::cout << bottom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
