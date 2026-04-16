/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:33:09 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/16 22:15:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed(void)
{
	this->_rawValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Converts integer to fixed-point by left bit shifting (multiplying by 256).
// rawValue = nbr << this->_fractBits = nbr * 256
Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawValue = nbr << this->_fractBits;
}

// Convert float to fixed-point multiplying by 256 to move the fractional part into the integer
// and rounding it to the nearest integer.
// rawValue = roundf(nbr * (1 << this->_fractBits)) = roundf(nbr * 256)
Fixed::Fixed(const float nbr)
{
    std::cout << "Float constructor called" << std::endl;
	
	float input;

	input = nbr;
	for (int i = 0; i < this->_fractBits; i++)
		input *= 2;
	this->_rawValue = roundf(input);
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_rawValue = src.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawValue = raw;
}

// Convert fixed-point to an integer by right bit shifting by _fractBits (dividing by 256), removing the fractional part.
// int = rawValue / 256
int Fixed::toInt(void) const
{
	return (this->_rawValue >> this->_fractBits);
}

// Convert fixed-point to a float by dividing the raw fixed-point value by 256 to restore the original float value.
// float = rawValue / 256
// (float)this->_rawValue / (1 << this->_fractBits) = rawValue / 256
float Fixed::toFloat(void) const
{
	float res;

	res = this->_rawValue;
	for (int i = 0; i < this->_fractBits; i++)
		res /= 2;
    return (res);
}

std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return (out);
}

// comparison operators
bool Fixed::operator>(const Fixed &src) const
{
	return (this->toFloat() > src.toFloat());
}

bool Fixed::operator<(const Fixed &src) const
{
	return (this->toFloat() < src.toFloat());
}

bool Fixed::operator>=(const Fixed &src) const
{
	return (this->toFloat() >= src.toFloat());
}

bool Fixed::operator<=(const Fixed &src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool Fixed::operator==(const Fixed &src) const
{
	return (this->toFloat() == src.toFloat());
}

bool Fixed::operator!=(const Fixed &src) const
{
	return (this->toFloat() != src.toFloat());
}

// aritmetic operators
Fixed Fixed::operator+(const Fixed &src) const
{
	return (this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
	return (this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
	return (this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
	return (this->toFloat() / src.toFloat());
}

// increment/decrement operators
Fixed &Fixed::operator++(void)
{
	this->_rawValue++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_rawValue--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_rawValue++;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_rawValue--;
	return (temp);
}

// min/max functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
