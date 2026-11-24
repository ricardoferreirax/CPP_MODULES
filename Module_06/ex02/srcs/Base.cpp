/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:54:43 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/24 16:22:47 by rmedeiro         ###   ########.fr       */
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


// GOAL: understand inheritance, polymorphism, virtual functions, static/dynamic types and 
//       runtime type identification using dynamic_cast.

// Base is parent class of A, B and C ->each derived class inherits from Base.
// A Base * or Base & can access objects of different derived types -> polymorphism ->allows us to work with A, B and C through a common Base type.

// static type ->known by compiler at compile time. | dynamic type ->real type of object at runtime.
// Base *ptr = new B(); -> static type of ptr: Base * | dynamic type of object: B. ->pointer remains Base *, even though actual object is B.
// pointer doesnt become a B pointer automatically->it remains a Base pointer that points to a B object

// compile time ->compiler translates source code into an executable. | runtime ->program is executing and objects are created and used.
// Base *ptr = generate(); ->at compile time, compiler knows generate() returns Base *. | ->at runtime, generate() randomly creates an A, B or C object.

// dynamic_cast uses runtime type info to check if requested conversion is valid for actual object ->allows C++ to identify types during program execution.
// it only attempts a type conversion and checks if that conversion is valid.

// function receives a pointer to Base: void identify(Base *p);
//  Base *ptr = new B(); and identify(ptr); ->inside identify(), p is a Base pointer ->we need to determine if it points to A, B or C.
// the program tries dynamic_cast<B *>(p); ->this conversion succeeds cause actual object is B->dynamic_cast returns a valid B * referring to that object.
//
// function receives a Base reference: void identify(Base &p);
// reference is another way to access an existing object, unlike a pointer, a valid reference must refer to an object
// Base *ptr = new B(); and identify(*ptr); ->* operator dereferences ptr, giving access to object so that it can be passed as a Base reference.
// inside identify(Base &p) ->we attempt dynamic_cast<B &>(p) ->since real object is B->conversion to B & succeeds.
// both identify() functions have the same goal->determine the real type of an object.
// difference is how object is received and how a failed runtime-checked dynamic_cast behaves.
//
// Pointer: void identify(Base *p); and dynamic_cast<A *>(p);
//          success -> returns A * | failure -> returns NULL
//
// Reference: void identify(Base &p); and dynamic_cast<A &>(p);
//            success -> returns A & | failure -> throws std::bad_cast

// virtual function supports runtime polymorphism ->overridden functions are selected according to real object type, not just pointer type.

// generate() uses std::rand() % 3 to choose A, B or C. ->new B() allocates and constructs a B object, returning B *.
// since B publicly inherits from Base, B * converts automatically to Base * ->this is called upcasting ->both pointers refer to same object.
// we return Base * so one function can return any of three derived types-> we use new so object remains alive after generate() returns.

// dynamic_cast performs runtime checked conversions in an inheritance hierarchy. ->it attempts downcasting: Base * -> A *, B * or C *.
// it uses runtime type to check the real object type. Unlike static_cast, it can detect invalid downcasts at runtime.

// Inheritance -> A, B and C derive from Base.
// Polymorphism -> Base * and Base & can access different derived objects.
// virtual -> enables runtime polymorphism and safe deletion through Base *.
// dynamic_cast -> checks the real object type at runtime.
// Pointer cast failure -> NULL | Reference cast failure -> std::bad_cast.
