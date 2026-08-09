/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:04:31 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 20:33:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	Base *ptr;

	std::srand(std::time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		std::cout << "----------------------------- Test " << i + 1 << " -----------------------------" << std::endl;

		ptr = generate();
		std::cout << std::endl;

		std::cout << "Pointer: ";
		identify(ptr);

		std::cout << "Reference: ";
		if (ptr != NULL)
			identify(*ptr);
		std::cout << std::endl;
		delete ptr;
	}

	std::cout << std::endl;
	return (0);
}
 