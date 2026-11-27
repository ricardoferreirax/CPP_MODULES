/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:20:57 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/27 13:21:09 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>

int main(void)
{
    Span a(5);
    Span b(10);
    Span c(a);
    Span d;

    d = b;
    return (0);
}
