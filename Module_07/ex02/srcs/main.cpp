/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:47:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/27 11:22:15 by rmedeiro         ###   ########.fr       */
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
	Array<std::string> words(3);
	Array<int> copy(nbrs);
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
	copy[2] = 84;
	copy[3] = 168;
	copy[4] = 336;
	std::cout << "nbrs[0]: " << nbrs[0] << " | copy[0]: " << copy[0] << std::endl;
	std::cout << "nbrs[1]: " << nbrs[1] << " | copy[1]: " << copy[1] << std::endl;
	std::cout << "nbrs[2]: " << nbrs[2] << " | copy[2]: " << copy[2] << std::endl;
	std::cout << "nbrs[3]: " << nbrs[3] << " | copy[3]: " << copy[3] << std::endl;
	std::cout << "nbrs[4]: " << nbrs[4] << " | copy[4]: " << copy[4] << std::endl << std::endl;
	words[0] = "Hello";
	words[1] = "World";
	words[2] = "42";
	std::cout << "words: ";
	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << words[i] << " ";
	std::cout << std::endl << std::endl;
	words_copy[0] = "Goodbye";
	words_copy[1] = "Universe";
	words_copy[2] = "24";
	std::cout << "words[0]: " << words[0] << " | words_copy[0]: " << words_copy[0] << std::endl;
	std::cout << "words[1]: " << words[1] << " | words_copy[1]: " << words_copy[1] << std::endl;
	std::cout << "words[2]: " << words[2] << "    | words_copy[2]: " << words_copy[2] << std::endl << std::endl;
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

// goal of this exercise is to create a generic Array class that stores elements of type T, 
// manages its own memory and provides safe access to its elements through operator [].
//
// unlike ex00 and ex01, where we created function templates, here we create a class template.
// a class template is a generic model from which compiler instantiates classes for different data types.
//
// template <typename T> -> T is a placeholder for a data type.