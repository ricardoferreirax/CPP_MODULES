/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:15:52 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/10 18:29:40 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

#include <iostream>
#include <string>

int	main(void)
{
	int	tab[] = {2, 3, 4, 5};
	const int const_tab[] = {1, 2, 3, 4};
	std::string	words[] = {"Project", "Module", ""};

	std::cout << std::endl;
	std::cout << "Integer array: ";
	::iter(tab, 4, printValue<int>);
	std::cout << std::endl;

	std::cout << "Apply function: ";
	::iter(tab, 4, squareValue<int>);
	::iter(tab, 4, printValue<int>);
	std::cout << std::endl << std::endl;

	std::cout << "Const array: ";
	::iter(const_tab, 4, printValue<int>);
	std::cout << std::endl << std::endl;

	std::cout << "String array:";
	::iter(words, 3, printValue<std::string>);
	std::cout << std::endl;

	std::cout << "After append:  ";
	::iter(words, 3, appendFortyTwo<std::string>);
	::iter(words, 3, printValue<std::string>);
	std::cout << std::endl << std::endl;

	return (0);
}
