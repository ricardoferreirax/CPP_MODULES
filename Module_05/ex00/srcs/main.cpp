/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 04:45:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/27 04:56:34 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Ricky", 1);
		std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;

		Bureaucrat b(a);
		std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;

		Bureaucrat c("Default", 150);
		std::cout << "Before assignment: " << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
		c = a;
		std::cout << "After assignment: " << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;

		// a.incrementGrade();
		// std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
