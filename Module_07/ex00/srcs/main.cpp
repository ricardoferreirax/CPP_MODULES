/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:16:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/26 14:53:41 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	int		a;
	int		b;
	float	e;
	float	f;
	double	g;
	double	h;

	a = 2;
	b = 3;
	std::string c = "chaine1";
	std::string d = "chaine2";
	e = 2.5f;
	f = 3.7f;
	g = 42.145;
	h = 21.653;
	a = 2;
	b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	c = "chaine1";
	d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	e = 2.5f;
	f = 3.7f;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
	g = 42.145;
	h = 21.653;
	::swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
	std::cout << "max(g, h) = " << ::max(g, h) << std::endl;
	return (0);
}

// a function template is a generic "model" that compiler creates specific functions for different data types.
// template is a generic model that allows create specialized functions for concrete data types.
// instead of writing a separate function for int, float, double ->we write a single generic implementation.
// this improves code reusability and avoids code duplication.
//
// template <typename T> ->declares a template with a type param T.
//
// typename ->tells compiler that T represents a data type.
// T ->placeholder for a concrete data type that will be determined when template is used.
// a placeholder temporarily is something that hasnt yet been specified ->T represents an unspecified data type.
// unlike a regular function param, which receives a value, a template type param represents a type.
//
// TEMPLATE ARGUMENT DEDUCTION: is process in which compiler determines template type param T by examining
// types of args passed to function.
//
// template <typename T>
// void swap(T &valueA, T &valueB);
//
// when we define template -> T doesnt represent a specific type yet.
// when we call function ->compiler compares types of args types of args with types of function params.
// we dont specify if T is an int, float, double, std::string or another data type.
// when function is called ->compiler determines T based on types of args passed to function.
//
// int a = 2, b = 3;
// ::swap(a, b); -> T represents int.
// float c = 2.5f, d = 3.7f;
// ::swap(c, d); -> T represents float.

// compiler examines both arguments: a is an int -> T must be int. | b is an int -> T must also be int.
// both args allow compiler to deduce same type -> T = int
//
/// ::min(2, 3); -> T = int -> valid. | ::min(2, 3.5); -> int and double -> compilation error.
// compiler cannot deduce two different types for same T.
// compiler then instantiates a function for each required type, using same generic implementation.
// this happens at compile time, not at runtime ->T is not a variable that changes its type during execution.

// TEMPLATE INSTANTIATION: is the process in which compiler uses a template to generate a specific function for a given type.
// after deducing T ->compiler substitutes T with concrete type and checks if function operations are valid for that type.
//
// The same template can be instantiated for different types:
//
// ::swap(a, b); -> swap<int> | ::swap(c, d); -> swap<std::string> | ::swap(e, f); -> swap<float> | ::swap(g, h); -> swap<double>
//
// each instantiated function works with a specific data type, but all versions are based on same generic implementation.
// compiler doesnt create a new version every time we call the function with same type.
// template argument deduction -> determines type T.
// template instantiation -> creates specific function.

// WHY TEMPLATES ARE DEFINED IN HEADER FILES:
// compiler needs access to complete template definition when instantiating it for a specific type.
// defining templates in header files makes their implementation visible to every source file that includes them.
//
// PASS BY VALUE VS PASS BY REFERENCE:
// T value ->receives a copy of original arg. ->does not modify original variable.
// T &value ->receives a reference to original arg. ->avoids copying and allows direct modification of original variable.
//
// swap(T &valueA, T &valueB) uses references because it needs to modify the original variables, not copies of them.
//
// CONST REFERENCES:
// const T &value ->accesses original arg w/out copying it and prevents modification through that reference.
// min() and max() use const references because they only need to compare args, not modify them.
// returning const T & avoids copying selected object and prevents modification through returned reference.
// The reference remains valid only while the original object is alive.
//
// SCOPE RESOLUTION OPERATOR (::):
// ::swap(), ::min() and ::max() explicitly call our functions defined in the global scope.
// this avoids ambiguity with std::swap, std::min and std::max.
