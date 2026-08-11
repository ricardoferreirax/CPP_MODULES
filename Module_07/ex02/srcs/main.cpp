/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:47:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/11 19:26:40 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

#include <iostream>
#include <string>

int	main(void)
{
	Array<int> a;
	Array<int> nbrs(5);
	Array<std::string> words(2);

	std::cout << std::endl;

	for (unsigned int i = 0; i < nbrs.size(); i++)
		nbrs[i] = (i + 1) * 10;

	try
	{
		for (unsigned int i = 0; i < nbrs.size(); i++)
			std::cout << "nbrs[" << i << "] = " << nbrs[i] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	for (unsigned int i = 0; i < words.size(); i++)
			words[i] = "Second";
		std::cout << std::endl;
	
	for (unsigned int i = 0; i < words.size(); i++)
			std::cout << "words[" << i << "] = " << words[i] << std::endl;
		std::cout << std::endl;

	Array<std::string> copy(words);
	std::cout << std::endl;

	Array<std::string> assign;

	assign = words;
	std::cout << std::endl;

	words[0] = "First";

	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << "words[" << i << "] = " << words[i] << std::endl;
	std::cout << std::endl;

	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << "words[" << i << "] = " << copy[i] << std::endl;
	std::cout << std::endl;

	for (unsigned int i = 0; i < assign.size(); i++)
		std::cout << "words[" << i << "] = " << assign[i] << std::endl;
	std::cout << std::endl;

	const Array<int> constant(nbrs);
	std::cout << std::endl;

	std::cout << constant[0] << std::endl << std::endl;

	// constant[0] = 42;

	return (0);
}
