/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:19:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/06 23:30:23 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"


int main(int ac, char **av)
{
	Harl	harl;
	
	if (ac != 2)
	{
		std::cerr << "Run: ./harlFilter <LEVEL>" << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}
