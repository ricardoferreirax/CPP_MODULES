/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 17:16:25 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/07/29 17:16:30 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Ricky", 10);
		Form form("Contract", 20, 30);

		std::cout << a << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat low("LowG", 100);
		Form form("Important Form", 50, 50);

		std::cout << low << std::endl;
		std::cout << form << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form invalidHigh("Invalid High", 0, 50);
		std::cout << invalidHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form invalidLow("Invalid Low", 151, 50);
		std::cout << invalidLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
