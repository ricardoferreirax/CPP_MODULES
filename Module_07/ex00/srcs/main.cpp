/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:16:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/10 14:18:34 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"
#include <iostream>

int	main(void)
{
	int	a;
	int	b;

	a = 2;
	b = 3;

	std::cout << "Before swap: a = " << a << " | b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap:  a = " << a << " | b = " << b << std::endl;

	return (0);
}
