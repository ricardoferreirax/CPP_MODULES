/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:54:43 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 20:10:47 by rmedeiro         ###   ########.fr       */
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
	std::cout << "[generate] Random choice: " << random << " -> ";

	if (random == 0)
	{
		std::cout << "Create object [A] and returns it as Base *" << std::endl << std::endl;
		return (new A());
	}
	if (random == 1)
	{
		std::cout << "Create object [B] and returns it as Base *" << std::endl << std::endl;
		return (new B());
	}
	std::cout << "Create object [C] and returns it as Base *" << std::endl << std::endl;
	return (new C());
}

void	identify(Base *p)
{
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
	catch (...)
	{
		
	}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "[identify reference] Base & refers to an object of type [B]" << std::endl;
		return ;
	}
	catch (...)
	{

	}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "[identify reference] Base & refers to an object of type [C]" << std::endl;
		return ;
	}
	catch (...)
	{
		
	}
	std::cout << "[identify reference] Unknown Base type" << std::endl;
}
 