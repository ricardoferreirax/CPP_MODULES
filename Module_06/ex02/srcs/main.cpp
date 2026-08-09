/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:04:31 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 19:43:21 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	Base *ptr;

	std::srand(std::time(NULL));
	std::cout << std::endl;

	ptr = generate();
	std::cout << std::endl;

	std::cout << "Generated type: ";
	identify(ptr);

	std::cout << std::endl;
	delete ptr;

	return (0);
}
