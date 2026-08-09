/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:55:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 20:10:44 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include <iostream>

A::A(void)
{
	std::cout << "[A] Default A created!" << std::endl;
}

A::~A(void)
{
	std::cout << "[A] A has been destroyed!" << std::endl;
}
 