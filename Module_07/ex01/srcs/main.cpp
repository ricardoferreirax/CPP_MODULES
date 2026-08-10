/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:20:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/10 17:21:51 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <iostream>

void	increment(int &value)
{
	value++;
}

int	main(void)
{
	int	array[] = {1, 2, 3, 4, 5};

	iter(array, 5, increment);

	for (int i = 0; i < 5; i++)
		std::cout << array[i] << " " << std::endl;

	return (0);
}
