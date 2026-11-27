/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:47:27 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/27 11:59:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Array<int> empty;
	Array<int> zero(0);
	Array<int> nbrs(5);

	std::cout << "\nnbrs: ";
	for (unsigned int i = 0; i < nbrs.size(); i++)
		std::cout << nbrs[i] << " ";
	std::cout << std::endl;
	for (unsigned int i = 0; i < nbrs.size(); i++)
		nbrs[i] = (i + 1) * 10;

	std::cout << std::endl;
	Array<int> copy(nbrs);

	std::cout << "\nbefore mod:" << std::endl;
	for (unsigned int i = 0; i < nbrs.size(); i++)
		std::cout << "nbrs[" << i << "]: " << nbrs[i] << " | copy[" << i << "]: " << copy[i] << std::endl;
	copy[0] = 24;
	nbrs[1] = 42;
	std::cout << "\nafter mod:" << std::endl;
	for (unsigned int i = 0; i < nbrs.size(); i++)
		std::cout << "nbrs[" << i << "]: " << nbrs[i] << " | copy[" << i << "]: " << copy[i] << std::endl;
	std::cout << "\nnbrs address: " << &nbrs[0] << std::endl;
	std::cout << "copy address: " << &copy[0] << std::endl << std::endl;

	const Array<int> constant(nbrs);

	std::cout << "\nconst: ";
	for (unsigned int i = 0; i < constant.size(); i++)
		std::cout << constant[i] << " ";
	std::cout << std::endl;
	// constant[0] = 42; // compilation error
	std::cout << std::endl;
	try
	{
		std::cout << nbrs[-1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Negative index: " << e.what() << std::endl;
	}
	try
	{
		std::cout << nbrs[nbrs.size()] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Invalid index: " << e.what() << std::endl;
	}
	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Empty array: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}


// goal of this exercise is to create a generic Array class that stores elements of type T,
// manages its own memory and provides safe access to its elements through operator [].
//
// unlike ex00 and ex01, where we created function templates, here we create a class template.
// a class template is a generic model from which compiler instantiates classes for different data types.
//
// template <typename T> -> T is a placeholder for a data type.

// shallow copY ->copies pointer instead of elements(this->_array = other._array;)
// both objects point to same memory allocation, modifying one array affects the other
//
// deep copy -> allocates independent memory and copies each element.
// this->_array = new T[other._length];
// this->_array[i] = other._array[i];
// each Array object owns its own memory allocation.
//
// Array<int> original(3);
// Array<int> copy(original);
//
// modifying original does not affect copy, modifying copy does not affect original.
