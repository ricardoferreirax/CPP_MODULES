/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:56:26 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/10 17:15:11 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T> void swap(T &valueA, T &valueB)
{
	T tmp;

	tmp = valueA;
	valueA = valueB;
	valueB = tmp;
}

template <typename T> const T &min(const T &valueA, const T &valueB)
{
	if (valueB < valueA)
		return (valueB);
	if (valueA < valueB)
		return (valueA);
	return (valueB);
}

template <typename T> const T &max(const T &valueA, const T &valueB)
{
	if (valueB > valueA)
		return (valueB);
	if (valueA > valueB)
		return (valueA);
	return (valueB);
}
	
#endif
 