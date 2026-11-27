/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:47:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/27 10:56:35 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	Array<int> empty;
	Array<int> zero(0);
	Array<int> nbrs(5);
	Array<int> copy(nbrs);
	Array<std::string> words(3);
	const Array<int> constant(nbrs);
	Array<std::string> words_copy(words);

	std::cout << std::endl;
	std::cout << "size of empty: " << empty.size() << std::endl;
	std::cout << "size of zero:  " << zero.size() << std::endl;
	std::cout << "size of nbrs:  " << nbrs.size() << std::endl;
	std::cout << "size of const: " << constant.size() << std::endl << std::endl;
	// constant[0] = 42; // compilation error
	std::cout << "original: ";
	for (unsigned int i = 0; i < nbrs.size(); i++)
		std::cout << nbrs[i] << " ";
	std::cout << " | modified: ";
	for (unsigned int i = 0; i < nbrs.size(); i++)
		nbrs[i] = (i + 1) * 10;
	for (unsigned int i = 0; i < nbrs.size(); i++)
		std::cout << nbrs[i] << " ";
	std::cout << std::endl << std::endl;
	copy[0] = 24;
	copy[1] = 42;
	std::cout << "nbrs[0]: " << nbrs[0];
	std::cout << " | copy[0]: " << copy[0] << std::endl << std::endl;
	std::cout << "nbrs[1]: " << nbrs[1];
	std::cout << " | copy[1]: " << copy[1] << std::endl << std::endl;
	words[0] = "Hello";
	words[1] = "World";
	words[2] = "42";
	std::cout << "words: ";
	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << words[i] << " ";
	std::cout << std::endl << std::endl;
	words_copy[0] = "Modified";
	std::cout << "words[0]: " << words[0];
	std::cout << " | words_copy[0]: " << words_copy[0] << std::endl << std::endl;
	try
	{
		std::cout << nbrs[-1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Negative index: " << e.what() << std::endl;
	}
	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Empty array: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
