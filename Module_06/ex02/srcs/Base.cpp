/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:54:43 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/24 10:58:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

// virtual destructor allows derived objects to be safely deleted through a base pointer
Base::~Base(void)
{
}

// randomly generates an A, B or C object and returns its address as a base pointer
Base	*generate(void)
{
	int	rand;

	rand = std::rand() % 3;
	std::cout << "[generate] choice: " << rand << " -> ";
	switch (rand)
	{
		case 0:
			std::cout << "creates object [A] and returns it as Base *" << std::endl << std::endl;
			return (new A()); // create/allocate an object of type A and return its address as a pointer to base
		case 1:
			std::cout << "creates object [B] and returns it as Base *" << std::endl << std::endl;
			return (new B()); // create/allocate an object of type B and return its address as a pointer to base
		case 2:
			std::cout << "creates object [C] and returns it as Base *" << std::endl << std::endl;
			return (new C()); // create an object of type C and return its address as a pointer to base
		default:
			return (NULL);
	}
}

// identifies real type of an object through a base pointer->dynamic_cast returns a valid pointer or NULL if cast fails
void	identify(Base *p)
{
	if (p == NULL)
	{
		std::cout << "[identify pointer] Null pointer" << std::endl;
		return ;
	}
	std::cout << "[identify pointer] Base * points to ";
	if (dynamic_cast<A *>(p)) // try converting base * to derived A*->if conversion succeeds, p points to an A object
		std::cout << "an object of type [A]" << std::endl;
	else if (dynamic_cast<B *>(p)) // try converting base * to derived B*->if conversion succeeds, p points to a B object
		std::cout << "an object of type [B]" << std::endl;
	else if (dynamic_cast<C *>(p)) // try converting base * to derived C*->if conversion succeeds, p points to a C object
		std::cout << "an object of type [C]" << std::endl;
	else // if none of above casts succeed->p points to an unknown Base object
		std::cout << "an unknown Base object" << std::endl;
}

// identifies real type of an object through a base reference->dynamic_cast returns a valid reference or throws an exception if cast fails
void	identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p); // try converting base & to derived A&->if conversion succeeds, p refers to an A object
		std::cout << "[identify reference] Base & refers to an object of type [A]" << std::endl;
		return ;
	}
	catch (const std::exception &e) // cast failed->catch exception and continue to next try block (next type)
	{
	}
	try
	{
		dynamic_cast<B &>(p); // try converting base & to derived B&->if conversion succeeds, p refers to a B object
		std::cout << "[identify reference] Base & refers to an object of type [B]" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		dynamic_cast<C &>(p); // try converting base & to derived C&->if conversion succeeds, p refers to a C object
		std::cout << "[identify reference] Base & refers to an object of type [C]" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	std::cerr << "[identify reference] Unknown Base type" << std::endl;
}
