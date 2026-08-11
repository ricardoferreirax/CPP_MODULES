/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:51:12 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/11 16:58:48 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>

template <typename T> Array<T>::Array(void)
	: _array(NULL), _length(0)
{
	std::cout << "[Array] Default constructor!" << std::endl;
}

template <typename T> Array<T>::Array(unsigned int n)
	: _array(NULL), _length(n)
{
	std::cout << "[Array] Parameter constructor!" << std::endl;
}

template <typename T> Array<T>::Array(const Array &other)
	: _array(NULL), _length(other._length)
{
	std::cout << "[Array] Copy constructor!" << std::endl;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
	std::cout << "[Array] Assignment operator!" << std::endl;
	(void)other;
	return (*this);
}

template <typename T> Array<T>::~Array(void)
{
	std::cout << "[Array] Destructor!" << std::endl;
}
