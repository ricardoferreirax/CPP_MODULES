/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:03:05 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/14 15:04:08 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(int ac, char **av)
{
    if (ac != 1)
    {
        std::cout << "Please enter only name of program [phonebook]" << std::endl;
        return (1);
    }
    (void)av;
    std::string command;
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
        command = handleLine();
        if (command == "ADD") 
            addNewContact();
        else if (command == "SEARCH") 
            showAllContacts();
        else if (command == "EXIT") 
		{
            std::cout << "Exiting program ..." << std::endl;
            break ;
        }
        else
            std::cout << "Invalid command! Please enter ADD, SEARCH, or EXIT" << std::endl;
    }
}
