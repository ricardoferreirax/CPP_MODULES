/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:20:20 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/27 13:24:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>

Span::Span()
{
	std::cout << "Default constructor called" << std::endl;
	this->_n = 0;
}

Span::Span(unsigned int n)
{
	std::cout << "Parameterized constructor called" << std::endl;
	this->_n = n;
}

Span::Span(const Span &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_n = other._n;
	this->_nbrs = other._nbrs;	
}

Span &Span::operator=(const Span &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_n = other._n;
		this->_nbrs = other._nbrs;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}
