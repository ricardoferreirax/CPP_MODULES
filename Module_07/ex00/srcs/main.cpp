/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:16:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/10 17:15:17 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"
#include <iostream>

int main( void ) 
{
	int a = 2;
	int b = 3;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;
}
 

// A template is a way to write generic code: instead of writing the same function or class 
// several times for different types, we write it once using a placeholder type, and 
// the compiler generates the concrete version that is needed when we use it.
// void swap(T &a, T &b) - T is not a real type yet. It is a placeholder that means the 
// actual type will be decided when this function is used.
// So, when we call swap(a, b) with a and b being integers, the compiler sees that both arguments 
// are integers and it creates a version of the swap function where T is replaced with int.

// when compiling the file containing: min(a, b); the compiler needs to see the full template definition, 
// not only its declaration. If the header only contained: T min(const T &a, const T &b); the compiler 
// would know that a template exists, but it would not know its implementation when it needs to generate 
// min<int>, min<double>, and so on.
// Templates are usually defined in header files because the compiler needs to see the full template definition 
// at the point where it instantiates the template for a specific type.
// Then every .cpp file that includes the header can see the complete template and instantiate whatever version it needs.

// Templates are usually defined in header files because the compiler must see the complete template definition when it 
// instantiates the template for a specific type. Unlike ordinary functions, template code is generated only when a concrete 
// type is used, so the implementation must be available at compile time.

// template <typename T> - typename tells the compiler that T represents a type. So:
//
// template <typename T>
// void swap(T &a, T &b)
//
// means: Define a function template with a type parameter called T.<Later, T could become: int, double, 
// char, std::string or even a user-defined class.
