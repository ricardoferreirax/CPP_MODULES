/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:59:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 20:10:39 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/B.hpp"
#include <iostream>

B::B(void)
{
	std::cout << "[B] Default B created!" << std::endl;
}

B::~B(void)
{
	std::cout << "[B] B has been destroyed!" << std::endl;
}
 