/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 06:22:51 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/13 06:50:06 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; ++i)
	{
		for (size_t j = 0; av[i][j]; ++j)
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(av[i][j])));
	}
	std::cout << std::endl;
	return (0);
}
