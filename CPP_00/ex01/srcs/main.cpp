/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:03:05 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/07 22:20:37 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include <cctype>
#include <cstdlib>

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
