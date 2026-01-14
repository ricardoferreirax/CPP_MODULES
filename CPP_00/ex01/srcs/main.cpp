/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:03:05 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/14 16:47:33 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include <cctype>
#include <cstdlib>

// Validate phone number (digits only, optional leading '+')
static bool	validatePhoneNumber(const std::string &value)
{
	if (value.empty())
		return (false);
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '+' && i == 0)
			continue ;
		if (value[i] == '+' && i != 0)
			return (false);
		if (!std::isdigit(static_cast<unsigned char>(value[i])))
			return (false);
	}
	return (true);
}

// Read a non-empty line from stdin
static std::string readUserInput()
{
	std::string line;
	while (true)
	{
		std::getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cout << "Reached end of input. Exiting..." << std::endl;
			std::exit(EXIT_FAILURE);
		}
		if (line.empty())
		{
			std::cout << "Empty input, try again: ";
			continue ;
		}
		return (line);
	}
}

// Handle ADD command
static void	executeAddCommand(PhoneBook &pb)
{
	Contact	c;

	std::string input;
	std::cout << "First Name: ";
	c.setFirstName(readUserInput());
	std::cout << "Last Name: ";
	c.setLastName(readUserInput());
	std::cout << "Nick Name: ";
	c.setNickName(readUserInput());
	std::cout << "Phone Number: ";
	input = readUserInput();
	while (!validatePhoneNumber(input))
	{
		std::cout << "Phone Number must contain only digits. Try again: ";
		input = readUserInput();
	}
	c.setPhoneNumber(input);
	std::cout << "Darkest Secret: ";
	c.setDarkestSecret(readUserInput());
	pb.storeContact(c);
	std::cout << "Contact added!" << std::endl;
}

// Handle SEARCH command
static void	executeSearchCommand(PhoneBook &pb)
{
	int	index;

	if (!pb.printContactsTable())
		return ;
	std::cout << "Enter index to view details: ";
	std::string input = readUserInput();
	while (!validatePhoneNumber(input))
	{
		std::cout << "Index must contain only digits. Try again: ";
		input = readUserInput();
	}
	index = std::atoi(input.c_str());
	pb.printContactDetails(index);
}

int	main(int ac, char **av)
{
	PhoneBook	phonebook;

	(void)av;
	if (ac != 1)
	{
		std::cout << "Please enter only name of program [phonebook]" << std::endl;
		return (1);
	}
	std::string command;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
		command = readUserInput();
		if (command == "ADD")
			executeAddCommand(phonebook);
		else if (command == "SEARCH")
			executeSearchCommand(phonebook);
		else if (command == "EXIT")
		{
			std::cout << "Exiting program ..." << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command! Please enter ADD, SEARCH, or EXIT" << std::endl;
	}
	return (0);
}
