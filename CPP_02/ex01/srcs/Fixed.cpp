/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:33:09 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/15 22:44:37 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractBits = 8;

Fixed::Fixed(void) : _fixedPointNbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNbr = nbr << this->_fractBits;
}

Fixed::Fixed(float const inputFloat)
{
    std::cout << "Float constructor called" << std::endl;
	float input = inputFloat;
	for (int i = 0; i < this->_fractBits; i++)
	{
		input *= 2;
	}
	this->_fixedPointNbr = roundf(input);
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointNbr = src._fixedPointNbr;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return (out);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointNbr >> this->_fractBits);
}

float Fixed::toFloat(void) const
{
	float res = this->_fixedPointNbr;
	for (int i = 0; i < this->_fractBits; i++)
	{
		res /= 2;
	}
    return (res);
}
