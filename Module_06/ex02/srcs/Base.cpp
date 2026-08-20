/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:54:43 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/20 23:07:09 by rmedeiro         ###   ########.fr       */
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
	int	random;

	random = std::rand() % 3;
	std::cout << "[generate] Random choice: " << random << " -> ";
	switch (random)
	{
		case 0:
			std::cout << "Creates object [A] and returns it as Base *" << std::endl << std::endl;
			return (new A());
		case 1:
			std::cout << "Creates object [B] and returns it as Base *" << std::endl << std::endl;
			return (new B());
		case 2:
			std::cout << "Creates object [C] and returns it as Base *" << std::endl << std::endl;
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
	}
	catch (const std::exception &e)
	{
		try
		{
			dynamic_cast<B &>(p);
			std::cout << "[identify reference] Base & refers to an object of type [B]" << std::endl;
		}
		catch (const std::exception &e)
		{
			try
			{
				dynamic_cast<C &>(p);
				std::cout << "[identify reference] Base & refers to an object of type [C]" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << "[identify reference] Unknown Base type" << std::endl;
			}
		}
	}
}
