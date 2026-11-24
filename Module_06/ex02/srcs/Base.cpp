/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:54:43 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/24 10:42:18 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base::~Base(void)
{
}

Base	*generate(void)
{
	int	rand;

	rand = std::rand() % 3;
	std::cout << "[generate] choice: " << rand << " -> ";
	switch (rand)
	{
		case 0:
			std::cout << "creates object [A] and returns it as Base *" << std::endl << std::endl;
			return (new A());
		case 1:
			std::cout << "creates object [B] and returns it as Base *" << std::endl << std::endl;
			return (new B());
		case 2:
			std::cout << "creates object [C] and returns it as Base *" << std::endl << std::endl;
			return (new C());
		default:
			return (NULL);
	}
}

void	identify(Base *p)
{
	if (p == NULL)
	{
		std::cout << "[identify pointer] Null pointer" << std::endl;
		return ;
	}
	std::cout << "[identify pointer] Base * points to ";
	if (dynamic_cast<A *>(p))
		std::cout << "an object of type [A]" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "an object of type [B]" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "an object of type [C]" << std::endl;
	else
		std::cout << "an unknown Base object" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "[identify reference] Base & refers to an object of type [A]" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "[identify reference] Base & refers to an object of type [B]" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "[identify reference] Base & refers to an object of type [C]" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	std::cerr << "[identify reference] Unknown Base type" << std::endl;
}
