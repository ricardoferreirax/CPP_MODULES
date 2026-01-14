/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:03:05 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/14 16:14:39 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include <cctype>
#include <cstdlib>

std::string handleLine()
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

static bool	isDigit(std::string value)
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

static void	addNewContact(PhoneBook &myPhoneBook)
{
	Contact	newContact;

	std::string input;
	std::cout << "First Name: ";
	input = handleLine();
	newContact.setFirstName(input);
	std::cout << "Last Name: ";
	input = handleLine();
	newContact.setLastName(input);
	std::cout << "Nick Name: ";
	input = handleLine();
	newContact.setNickName(input);
	std::cout << "Phone Number: ";
	input = handleLine();
	while (!isDigit(input))
	{
		std::cout << "Phone Number must contain only digits. Try again: ";
		input = handleLine();
	}
	newContact.setPhoneNumber(input);
	std::cout << "Darkest Secret: ";
	input = handleLine();
	newContact.setDarkestSecret(input);
	myPhoneBook.addContact(newContact);
	std::cout << "Contact added!" << std::endl;
}

static void	showAllContacts(PhoneBook &myPhoneBook)
{
	int	index;

	if (!myPhoneBook.displayAllContacts())
		return ;
	std::cout << "Enter index to view details: ";
	std::string input = handleLine();
	while (!isDigit(input))
	{
		std::cout << "Index must contain only digits. Try again: ";
		input = handleLine();
	}
	index = std::atoi(input.c_str());
	myPhoneBook.searchContact(index);
}

int	main(int ac, char **av)
{
	PhoneBook	myPhoneBook;

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
		command = handleLine();
		if (command == "ADD")
			addNewContact(myPhoneBook);
		else if (command == "SEARCH")
			showAllContacts(myPhoneBook);
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
