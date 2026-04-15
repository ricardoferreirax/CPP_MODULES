/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:57:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/15 22:48:43 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

/* 
Area for Triangle
Area = | Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By) | * 1/2 

Ax = X coordinate of point A
Ay = Y coordinate of point A
Bx = X coordinate of point B
By = Y coordinate of point B
Cx = X coordinate of point C
Cy = Y coordinate of point C
| | = Absolute value (ensure area is positive)
*/

Fixed Point::triangleArea(const Point a, const Point b, const Point c)
{
	Fixed area;
	
	area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + 
				c.getX() * (a.getY() - b.getY())) / Fixed(2);
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point area;
	Fixed abc;
	Fixed abp;
	Fixed acp;
	Fixed bcp;

	abc = area.triangleArea(a, b, c);
	abp = area.triangleArea(a, b, point);
	acp = area.triangleArea(a, c, point);
	bcp = area.triangleArea(b, c, point);
	if (abc == Fixed(0))
		return (false);
	if (abp == Fixed(0) || acp == Fixed(0) || bcp == Fixed(0))
		return (false);
	if (abc == abp + acp + bcp)
		return (true);
	return (false);
}
