/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:50:12 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/14 15:15:13 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe constructor called." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_nbrs = other._nbrs;
	this->_main_chain = other._main_chain;
	this->_pending_groups = other._pending_groups;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_nbrs = other._nbrs;
		this->_main_chain = other._main_chain;
		this->_pending_groups = other._pending_groups;
	}
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

void PmergeMe::print_nbrs(size_t group_size) const
{
	std::cout << "Vector:";
	for (size_t i = 0; i < this->_nbrs.size(); i++)
	{
		if (group_size > 0 && i % group_size == 0) // check if new group starts
			std::cout << " [";
		else
			std::cout << " "; // add a space between nbrs
		std::cout << this->_nbrs[i]; // print current nbr
		if (group_size > 0)
		{
			if ((i + 1) % group_size == 0) // check if group is complete
				std::cout << "]";
			else if (i == this->_nbrs.size() - 1) // check if is last nbr
				std::cout << "]";
		}
	}
	std::cout << std::endl;
}

// pending: b1  b2  b3  b4
// winner:  a1  a2  a3  a4
void PmergeMe::show_insertion_groups(size_t group_size) const
{
	size_t block_size;

	block_size = group_size * 2;
	for (size_t i = 0; i < this->_nbrs.size() / block_size; i++) // iterate each block
	{
		std::cout << "pending: [";
		for (size_t j = 0; j < block_size; j++) // iterate each nbr in block
		{
			if (j == group_size)
				std::cout << "] | winner: [";
			else if (j > 0)
				std::cout << " ";
			std::cout << this->_nbrs[i * block_size + j]; // print current nbr
		}
		std::cout << "]" << std::endl;
	}
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
	size_t	block_size;

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

// winner : a1  a2  a3  a4
// pending: b1  b2  b3  b4
//
// main chain: b1  a1  a2  a3  a4
// pending   :     b2  b3  b4
void PmergeMe::build_chains(size_t group_size)
{
	size_t	block_size;
	size_t	pos;

	if (group_size == 0 || group_size > this->_nbrs.size() / 2)
		return ;
	block_size = group_size * 2;
	this->_main_chain.clear(); // clear groups from previous level
	this->_pending_groups.clear();
	for (size_t i = 0; i < this->_nbrs.size() / block_size; i++)
	{
		pos = i * block_size;
		this->_pending_groups.push_back(pos); // smaller group
		this->_main_chain.push_back(pos + group_size); // larger group
	}
}

void PmergeMe::merge_insertion_sort(size_t group_size)
{
	size_t	block_size;

	if (group_size == 0 || group_size > this->_nbrs.size() / 2) // insufficient elements to sort
		return ;
	block_size = group_size * 2;
	compare_groups(group_size);
	print_nbrs(block_size);
	merge_insertion_sort(block_size);
	std::cout << "\nInsertion level: " << group_size << std::endl;
	show_insertion_groups(group_size);
	build_chains(group_size);
}
