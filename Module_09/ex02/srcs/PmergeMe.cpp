/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:50:12 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/12 17:56:10 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	std::cout << "PmergeMe assignment operator called" << std::endl;
    if (this != &other)
    {
		
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}
