/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:19:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/10 18:24:47 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename Data, typename Func> void iter(Data *array, const int len, Func func)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < len)
	{
		func(array[i]);
		i++;
	}
}

template <typename Data, typename Func> void iter(const Data *array, const int len, Func func)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < len)
	{
		func(array[i]);
		i++;
	}
}

template <typename Value> void printValue(const Value &value)
{
	std::cout << value << " ";
}

template <typename Value> void squareValue(Value &value)
{
	value *= value;
}

template <typename Value> void appendFortyTwo(Value &value)
{
	value += "_42";
}

#endif
