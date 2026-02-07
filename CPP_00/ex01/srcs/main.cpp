/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:03:05 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/07 23:54:12 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include <cctype>
#include <cstdlib>

int main(int ac, char **av)
{
	PhoneBook phoneBook;
	std::string command;

	if (ac > 1)
	{
		std::cout << "Error: this program does not accept arguments." << std::endl;
		std::cout << "Usage: " << av[0] << std::endl;
		return (1);
	}
	std::cout << "-------------- PhoneBook --------------" << std::endl;
	std::cout << "- 1. Add a Contact" << std::endl;
	std::cout << "- 2. Search for a Contact" << std::endl;
	std::cout << "- 3. Exit" << std::endl;
	std::cout << "----------------------------------------\n" << std::endl;
	std::cout << "Enter Your Option: (ADD, SEARCH, EXIT)\n" << std::endl;

	std::cout << "> ";
	while (std::getline(std::cin, command))
	{
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			return (0);
		}
		else if (!command.empty())
		{
			std::cout << "\nInvalid command!" << std::endl;
			std::cout << "Please use: ADD, SEARCH or EXIT.\n" << std::endl;
		}
		std::cout << "> ";
	}
	std::cout << std::endl;
	return (0);
}



