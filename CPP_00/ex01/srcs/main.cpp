/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:03:05 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/26 15:23:46 by rmedeiro         ###   ########.fr       */
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
	std::cout << "--------------------------------------\n" << std::endl;
	std::cout << "-> [ADD]: To Add a Contact!" << std::endl;
	std::cout << "-> [SEARCH]: To Search for a Contact!" << std::endl;
	std::cout << "-> [EXIT]: Exit the Phonebook!" << std::endl;
	std::cout << "\nChoose: (ADD, SEARCH, EXIT)\n" << std::endl;

	std::cout << "> ";
	while (std::getline(std::cin, command))
	{
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
		{
			std::cout << "\nGoodbye!\n" << std::endl;
			std::cout << "--------------------------------------" << std::endl;

			return (0);
		}
		else if (!command.empty())
			std::cout << "\nInvalid command! Choose: ADD, SEARCH or EXIT.\n" << std::endl;
		std::cout << "> ";
	}
	std::cout << std::endl;
	std::cout << "\n--------------------------------------" << std::endl;
	return (0);
}



