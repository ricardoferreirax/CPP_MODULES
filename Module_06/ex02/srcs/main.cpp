/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:04:31 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/24 10:43:48 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	Base	*ptr;
	Base	 base;
	A		 a;
	B		 b;
	C		 c;

	std::srand(std::time(NULL));
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n------ Test " << i + 1 << " ------\n" << std::endl;
		ptr = generate();
		std::cout << "pointer: ";
		identify(ptr);
		std::cout << "reference: ";
		if (ptr != NULL)
			identify(*ptr);
		delete	ptr;
	}
	std::cout << "\n------ identify derived classes ------\n" << std::endl;
	std::cout << "pointer A: ";
	identify(&a);
	std::cout << "reference A: ";
	identify(a);
	std::cout << "pointer B: ";
	identify(&b);
	std::cout << "reference B: ";
	identify(b);
	std::cout << "pointer C: ";
	identify(&c);
	std::cout << "reference C: ";
	identify(c);
	std::cout << "\n------ NULL pointer ------\n" << std::endl;
	ptr = NULL;
	std::cout << "Pointer: ";
	identify(ptr);
	std::cout << "\n------ identify Base class ------\n" << std::endl;
	std::cout << "pointer: ";
	identify(&base);
	std::cout << "reference: ";
	identify(base);
	std::cout << std::endl;
	return (0);
}
