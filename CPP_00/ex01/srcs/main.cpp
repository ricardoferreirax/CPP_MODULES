/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:03:05 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/07 23:26:32 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include <cctype>
#include <cstdlib>

int main(int argc, char **argv)
{
	PhoneBook   phonebook;
	std::string cmd;

	(void)argv;

	if (argc != 1)
	{
		std::cout << "This program does not accept arguments." << std::endl;
		return 1;
	}
	std::cout << "Available commands: ADD | SEARCH | EXIT" << std::endl;

	std::cout << "> ";
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.searchContacts();
		else if (cmd == "EXIT")
		{
			std::cout << "Goodbye! Contacts are lost forever." << std::endl;
			return 0;
		}
		std::cout << "> ";
	}
	std::cout << std::endl << "Input ended. Exiting." << std::endl;
	return 0;
}
