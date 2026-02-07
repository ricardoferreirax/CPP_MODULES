/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:03:05 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/07 23:43:36 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include <cctype>
#include <cstdlib>

int main(int ac, char **av)
{
	PhoneBook phoneBook;
	std::string command;

	(void)av;
	if (ac != 1)
	{
		std::cout << "This program does not take any arguments." << std::endl;
		return (1);
	}

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;

	std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
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
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
	}
	std::cout << std::endl;
	return (0);
}
