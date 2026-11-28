/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:20:57 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/28 19:11:27 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>
#include <exception>

int main(void)
{
    try
    {
        Span sp(3);

        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
		std::cout << "numbers: ";
		sp.printNumbers();
        sp.addNumber(40);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Span sp(0);

        sp.addNumber(10);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    return (0);
}
