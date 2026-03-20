/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:14:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/20 14:50:32 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &src);
		Point &operator=(const Point &src);
		~Point(void);

		Fixed getX(void) const;
		Fixed getY(void) const;

		static Fixed triangleArea(Point const a, Point const b, Point const c);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif