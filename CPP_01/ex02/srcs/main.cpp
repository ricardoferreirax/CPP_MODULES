/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:37:39 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/04 16:07:45 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac != 1)
    {
        std::cout << "Usage: " << av[0] << std::endl;
        return (1);
    }
    std::string     str = "HI THIS IS BRAIN";
    std::string*    stringPTR = &str; // a pointer to the string
    std::string&    stringREF = str;  // a reference to the string

    std::cout << "--------- PRINT THE MEMORY ADDRESS OF VARIABLES ---------\n\n";
    std::cout << "The memory address of the string variable: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << "\n--------- PRINT THE VALUES OF VARIABLES ---------\n\n";
    std::cout << "The value of the string variable: " << str << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}
