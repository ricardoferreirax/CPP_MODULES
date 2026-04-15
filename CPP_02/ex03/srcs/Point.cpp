/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:16:51 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/15 22:47:08 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	(void)src;
	return (*this);
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}
