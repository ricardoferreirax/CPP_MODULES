/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:47:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/11 17:25:48 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

#include <iostream>

int	main(void)
{
	Array<int> a;
	Array<int> b(5);
	Array<int> c(b);

	std::cout << std::endl;

	return (0);
}
