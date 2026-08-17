/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:02:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/17 17:01:40 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	
	return (0);
}
