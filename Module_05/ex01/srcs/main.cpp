/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:55:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/13 18:40:30 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main(void)
{
	std::cout << std::endl;
	try
	{
		Bureaucrat ricky("Ricky", 10);
		Form form("Form", 20, 30);

		std::cout << std::endl;

		std::cout << ricky << std::endl;
		std::cout << form << std::endl << std::endl;

		ricky.signForm(form);

		std::cout << std::endl;
		std::cout << form << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;

	try
	{
		Bureaucrat low("Low", 100);
		Form form("Form", 50, 30);

		std::cout << std::endl;

		std::cout << low << std::endl;
		std::cout << form << std::endl << std::endl;

		low.signForm(form);

		std::cout << std::endl;
		std::cout << form << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;

	try
	{
		Form invalid("Invalid Form", 0, 50);

		std::cout << invalid << std::endl; // This line is never executed because the constructor throws.
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;

	try
	{
		Form invalid("Invalid Form", 50, 151);

		std::cout << invalid << std::endl; // This line is never executed because the constructor throws.
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;

	{
		Form original("Form", 42, 24);
		Form copy(original);

		std::cout << std::endl;

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl << std::endl;
	}

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;

	{
		Form first("First Form", 10, 20);
		Form second("Second Form", 100, 120);
		Bureaucrat signer("Signer", 1);

		std::cout << std::endl;

		std::cout << "Before assignment:" << std::endl;
		std::cout << first << std::endl;
		std::cout << second << std::endl << std::endl;

		signer.signForm(first);
		std::cout << std::endl;
		
		second = first;

		std::cout << std::endl;
		std::cout << "After assignment:" << std::endl;  // Only the mutable member _signed is copied by the assignment operator. _name, _signGrade and _executeGrade 
														// are const members and cannot be reassigned after construction
		std::cout << first << std::endl;
		std::cout << second << std::endl << std::endl;
	}

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;

	{
		Form test("Const Form", 20, 30);

		std::cout << test << std::endl;

		// These members are private and/or const, so they cannot be modified directly from outside the Form class.

		// test._name = "new form";          // Does not compile.
		// test._signGrade = 1;              // Does not compile.
		// test._executeGrade = 1;           // Does not compile.
		// test.getName() = "new form";      // Does not compile.
	}

	std::cout << std::endl;
	return (0);
}