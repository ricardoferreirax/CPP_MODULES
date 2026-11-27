/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:15:52 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/27 10:14:31 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <cstddef>
#include <iostream>
#include <string>

int	main(void)
{
	int			tab[] = {2, 3, 4, 5,1000000000};
	const int	const_tab[] = {1, 2, 3, 4};
	std::string words[] = {"Project", "Module", ""};
	const std::string const_words[] = {"Hello", "World", "42"};
	float		floats[] = {1.5f, 2.5f, 3.5f};
	int			*null;

	null = NULL;
	std::cout << "array before: ";
	::iter(tab, 5, printValue<int>);
	std::cout << "\narray after:  ";
	::iter(tab, 5, squareValue<int>);
	::iter(tab, 5, printValue<int>);
	std::cout << "\n\nconst array: ";
	// ::iter(const_tab, 4, squareValue<int>);
	::iter(const_tab, 4, printValue<int>);
	std::cout << "\n\nfloat array before: ";
	::iter(floats, 3, printValue<float>);
	std::cout << "\nfloat array after:  ";
	::iter(floats, 3, squareValue<float>);
	::iter(floats, 3, printValue<float>);
	std::cout << "\n\nstring array before: ";
	::iter(words, 3, printValue<std::string>);
	std::cout << "\nstring array after: ";
	::iter(words, 3, appendFortyTwo<std::string>);
	::iter(words, 3, printValue<std::string>);
	std::cout << "\n\nconst string array: ";
	// ::iter(const_words, 3, appendFortyTwo<std::string>);
	::iter(const_words, 3, printValue<std::string>);
	std::cout << "\n\nnull pointer: ";
	::iter(null, 4, squareValue<int>);
	::iter(null, 4, printValue<int>);
	std::cout << "crash no more";
	std::cout << "\n\nempty array: ";
	::iter(tab, 0, printValue<int>);
	std::cout << "there's nothing here" << std::endl;
	return (0);
}



// goal of this exercise is to create a generic function that iterates through an array 
// and applies a given operation to each of its elements.
// unlike ex00, where operation was defined inside template (swap, min or max), iter() receives 
// the operation as an argument.

// template <typename Data, typename Func>
// Data -> placeholder for type of array elements.
// Func -> placeholder for type of the callable.
//
// array -> receives address of first element.
// len   -> receives a constant copy of nbr of elements.
// func  -> receives the callable to execute on each element.

// int tab[] = {2, 3, 4, 5};
// ::iter(tab, 4, squareValue<int>);
//
// when tab is passed to iter(), array is converted into a pointer to its first element 
// squareValue<int> identifies a specific specialization of the squareValue function template.
// since we pass the function without calling it ->it is implicitly converted into a function pointer.
//
// compiler examines args and deduces: Data = int | Func = void (*)(int &)
// it then instantiates a version of iter() equivalent to: void iter(int *array, const int len, void (*func)(int &));
// therefore, func now points to squareValue<int>.
//
// using Func instead of a fixed function pointer type allows iter() to accept functions with different param and return types,

// Inside iter(), the following instruction func(array[i]);
//
// Calls the function pointed to by func, passing the current array element as its argument.
// Since func points to squareValue<int>, this is equivalent to: squareValue<int>(array[i]);
//
// The original array is modified because squareValue() receives each element by reference rather than by value.

// CONST VS NON-CONST REFERENCES:
// Value &value: receives a reference to original object ->allowing modification when Value is a non-const type.
// const Value &value: receives a reference to original object ->but prevents modification through that reference.
// both use references to avoid copying the elements.
// A const reference can accept const and non-const elements,
// while a non-const reference cannot accept const elements.

// Data *array: allows access to and modification of non-const elements.
// const Data *array: allows access to the elements but prevents modification through pointer.
//
// When we call iter(), the compiler selects the most appropriate overload based on args.
