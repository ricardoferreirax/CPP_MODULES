/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:41:03 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/15 22:47:00 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Point.hpp"

int main()
{
    Point a(0,0);
    Point b(10,0);
    Point c(5,10);
    
    Point p1(5,5);    // inside
    Point p2(0,0);    // vertex
    Point p3(5,0);    // edge
    Point p4(10,10);  // outside

    std::cout << "the point1 is " << (bsp(a,b,c,p1) ? "inside" : "outside") << " the triangle." << "\n";
    std::cout << "the point2 is " << (bsp(a,b,c,p2) ? "inside" : "outside") << " the triangle." << "\n";
    std::cout << "the point3 is " << (bsp(a,b,c,p3) ? "inside" : "outside") << " the triangle." << "\n";
    std::cout << "the point4 is " << (bsp(a,b,c,p4) ? "inside" : "outside") << " the triangle." << "\n";
}
