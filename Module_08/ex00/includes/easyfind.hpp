/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 21:14:46 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/22 23:06:20 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T> void easyfind(T &container, int value)
{
	typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		std::cout << "F: " << *it << " at index " << (it - container.begin()) << std::endl;
	else
		std::cout << "NF" << std::endl;
}

#endif
