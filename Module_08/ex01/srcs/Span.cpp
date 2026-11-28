/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:20:20 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/28 19:10:00 by rmedeiro         ###   ########.fr       */
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

void Span::addNumber(int nbr)
{
	if (this->_nbrs.size() >= this->_n)
		throw std::runtime_error("cannot add more numbers");
	this->_nbrs.push_back(nbr);
}

void Span::printNumbers()
{
	std::vector<int>::iterator it;

	for (it = this->_nbrs.begin(); it != this->_nbrs.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
