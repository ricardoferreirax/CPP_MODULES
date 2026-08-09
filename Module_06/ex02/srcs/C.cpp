/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:59:33 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 20:10:52 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/C.hpp"
#include <iostream>

C::C(void)
{
	std::cout << "[C] Default C created!" << std::endl;
}

C::~C(void)
{
	std::cout << "[C] C has been destroyed!" << std::endl;
}
 