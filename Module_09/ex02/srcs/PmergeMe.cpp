/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:50:12 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/14 12:29:23 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe constructor called." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		this->_nbrs = other._nbrs;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called." << std::endl;
}

void PmergeMe::validate_input(int ac, char **av)
{
	int	nb;
	int	digit;

	std::string input;
	if (ac < 2)
		throw std::invalid_argument("No numbers provided.");
	this->_nbrs.clear(); // clear before adding new nbrs
	for (int i = 1; i < ac; ++i)
	{
		nb = 0;
		input = av[i];
		if (input.empty())
			throw std::invalid_argument("Empty argument.");
		for (size_t j = 0; j < input.size(); ++j)
		{
			if (input[j] < '0' || input[j] > '9')
				throw std::invalid_argument("Invalid number.");
			digit = input[j] - '0';
			if (nb > (INT_MAX - digit) / 10)
				throw std::out_of_range("Integer overflow.");
			nb = nb * 10 + digit;
		}
		if (nb == 0)
			throw std::invalid_argument("Number must be positive.");
		this->_nbrs.push_back(nb); // add nb to vector
	}
}

void PmergeMe::print_nbrs() const
{
	std::cout << "Vector:";
	for (size_t i = 0; i < this->_nbrs.size(); ++i)
		std::cout << " " << this->_nbrs[i];
	std::cout << std::endl;
}

void PmergeMe::print_groups(size_t group_size) const
{
	if (group_size == 0)
		return ;
	for (size_t i = 0; i < this->_nbrs.size(); i++)
	{
		if (i % group_size == 0) // check if new group starts
			std::cout << "[";
		std::cout << this->_nbrs[i]; // print current nbr
		if ((i + 1) % group_size == 0) // check if group is complete
			std::cout << "] ";
		else if (i == this->_nbrs.size() - 1) // check if this is last nbr
			std::cout << "] ";
		else
			std::cout << " "; // Add a space between numbers
	}
	std::cout << std::endl;
}

void PmergeMe::swap_groups(size_t a, size_t b, size_t group_size)
{
	int	temp;

	for (size_t i = 0; i < group_size; ++i)
	{
		temp = this->_nbrs[a + i];
		this->_nbrs[a + i] = this->_nbrs[b + i];
		this->_nbrs[b + i] = temp;
	}
}

void PmergeMe::compare_groups(size_t group_size)
{
	size_t	pos;
	size_t	a_max;
	size_t	b_max;

	size_t block_size; // size of two groups to compare
	if (group_size == 0 || group_size > this->_nbrs.size() / 2)
		// insufficient elements to compare
		return ;
	block_size = group_size * 2;
	for (size_t i = 0; i < this->_nbrs.size() / block_size; i++)
	{
		pos = i * block_size;
		a_max = pos + group_size - 1;
		b_max = pos + block_size - 1;
		if (this->_nbrs[a_max] > this->_nbrs[b_max])
			swap_groups(pos, pos + group_size, group_size);
	}
}

void PmergeMe::sort_nbrs()
{
	size_t	group_size;

	group_size = 1;
	compare_groups(group_size);
	print_groups(group_size * 2);
	group_size = 2;
	compare_groups(group_size);
	print_groups(group_size * 2);
	group_size = 4;
	compare_groups(group_size);
	print_groups(group_size * 2);
}
