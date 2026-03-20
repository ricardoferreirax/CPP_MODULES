/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:16:51 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/20 13:44:47 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	std::cout << "[Point] Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	std::cout << "[Point] Float constructor called" << std::endl;
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
	std::cout << "[Point] Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &src)
{
	std::cout << "[Point] Copy assignment operator called" << std::endl;
	(void)src;
	return (*this);
}

Point::~Point(void)
{
	std::cout << "[Point] Destructor called" << std::endl;
}
