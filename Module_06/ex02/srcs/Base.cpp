/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:54:43 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/08 21:09:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <iostream>
#include <cstdlib>

Base::~Base(void)
{
	std::cout << "[Base] Base has been destroyed!" << std::endl;
}

Base *generate(void)
{
	int	random;

	random = std::rand() % 3;
	std::cout << "Random instances generated: " << random << std::endl << std::endl;
	if (random == 0)
	{
		std::cout << "Generated instance of A" << std::endl << std::endl;
		return (new A());
	}
	if (random == 1)
	{
		std::cout << "Generated instance of B" << std::endl << std::endl;
		return (new B());
	}
	std::cout << "Generated instance of C" << std::endl << std::endl;
	return (new C());
}
