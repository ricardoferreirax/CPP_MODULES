/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:53:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/12 17:55:37 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(void)
{
	PmergeMe	first;
	PmergeMe	third;

	PmergeMe second(first);
	third = first;
	return (0);
}
