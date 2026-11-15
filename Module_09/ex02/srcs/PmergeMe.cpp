/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:50:12 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/15 20:52:35 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe constructor called." << std::endl;
}

PmergeMe::PmergeMe(int ac, char **av)
{
	int	nb;
	int	digit;

	std::string input;
	if (ac < 2)
		throw std::invalid_argument("No numbers provided.");
	for (int i = 1; i < ac; i++)
	{
		nb = 0;
		input = av[i];
		if (input.empty())
			throw std::invalid_argument("Empty argument.");
		for (size_t j = 0; j < input.size(); j++)
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
		this->_nbrs.push_back(nb);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_nbrs = other._nbrs;
	this->_main_chain = other._main_chain;
	this->_pend_groups = other._pend_groups;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_nbrs = other._nbrs;
		this->_main_chain = other._main_chain;
		this->_pend_groups = other._pend_groups;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called." << std::endl;
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

void PmergeMe::print_nbrs(size_t group_size) const
{
	std::cout << "\nIndex: ";
	for (size_t i = 0; i < this->_nbrs.size(); i++)
	{
		if (group_size > 0 && i % group_size == 0)
			std::cout << " [";
		else
			std::cout << " ";
		std::cout << i;
		if (group_size > 0 && ((i + 1) % group_size == 0 || i == this->_nbrs.size() - 1))
			std::cout << "]";
	}
	std::cout << std::endl;
	std::cout << "Vector:";
	for (size_t i = 0; i < this->_nbrs.size(); i++)
	{
		if (group_size > 0 && i % group_size == 0)
			std::cout << " [";
		else
			std::cout << " ";
		std::cout << this->_nbrs[i];
		if (group_size > 0 && ((i + 1) % group_size == 0
				|| i == this->_nbrs.size() - 1))
			std::cout << "]";
	}
	std::cout << std::endl;
}

// pending: b1  b2  b3  b4
// winner:  a1  a2  a3  a4
void PmergeMe::print_chains(size_t group_size, bool show_pairs) const
{
	size_t block_size;
	size_t pos;

	block_size = group_size * 2;
	if (show_pairs)
	{
		for (size_t i = 0; i < this->_nbrs.size() / block_size; i++)
		{
			pos = i * block_size;
			std::cout << "Loser (" << pos << "): [";
			for (size_t j = 0; j < block_size; j++)
			{
				if (j == group_size)
					std::cout << "] | Winner (" << pos + group_size << "): [";
				else if (j > 0)
					std::cout << " ";
				std::cout << this->_nbrs[pos + j];
			}
			std::cout << "]" << std::endl;
		}
		std::cout << "\nPending groups: ";
		for (size_t i = 0; i < this->_pend_groups.size(); i++)
		{
			pos = this->_pend_groups[i];
			std::cout << "(" << pos << "): [";
			for (size_t j = 0; j < group_size; j++)
			{
				if (j > 0)
					std::cout << " ";
				std::cout << this->_nbrs[pos + j];
			}
			std::cout << "] ";
		}
		std::cout << std::endl;
	}
	std::cout << "Main chain: ";
	for (size_t i = 0; i < this->_main_chain.size(); i++)
	{
		pos = this->_main_chain[i];
		std::cout << "(" << pos << ")[";
		for (size_t j = 0; j < group_size; j++)
		{
			if (j > 0)
				std::cout << " ";
			std::cout << this->_nbrs[pos + j];
		}
		std::cout << "] ";
	}
	std::cout << std::endl;
}

void PmergeMe::insert_pending_groups(size_t group_size)
{
	size_t	pend_pos;
	size_t	left;
	size_t	right;
	size_t	mid;
	int		pend_max;
	int		mid_max;

	for (size_t i = 0; i < this->_pend_groups.size(); i++)
	{
		pend_pos = this->_pend_groups[i]; // starting index in _nbrs
		pend_max = this->_nbrs[pend_pos + group_size - 1]; // last element of pending group
		left = 0;
		right = this->_main_chain.size();
		while (left < right)
		{
			mid = left + (right - left) / 2; // find mid pos of main chain
			mid_max = this->_nbrs[this->_main_chain[mid] + group_size - 1]; // max value at mid pos of main chain
			if (pend_max < mid_max)
				right = mid; // search left half
			else
				left = mid + 1; // otherwise->search right half
		}
		this->_main_chain.insert(this->_main_chain.begin() + left, pend_pos);
	}
}

void PmergeMe::merge_insertion_sort(size_t group_size)
{
	size_t block_size;
	size_t pos;
	size_t a_max;
	size_t b_max;
	std::vector<int> sorted;

	if (group_size == 0 || group_size > this->_nbrs.size() / 2)
		return ;
	block_size = group_size * 2; // size of two groups to be compared
	for (size_t i = 0; i < this->_nbrs.size() / block_size; i++)
	{
		pos = i * block_size;
		a_max = pos + group_size - 1;
		b_max = pos + block_size - 1;
		if (this->_nbrs[a_max] > this->_nbrs[b_max])
			swap_groups(pos, pos + group_size, group_size);
	}
	print_nbrs(block_size);
	merge_insertion_sort(block_size);
	std::cout << "\nInsertion level: " << group_size << std::endl;
	this->_main_chain.clear();
	this->_pend_groups.clear();
	for (size_t i = 0; i < this->_nbrs.size() / block_size; i++)
	{
		pos = i * block_size;
		if (i == 0)
			this->_main_chain.push_back(pos);
		else
			this->_pend_groups.push_back(pos);
		this->_main_chain.push_back(pos + group_size);
	}
	std::cout << "\nBefore insertion:" << std::endl;
	print_chains(group_size, true);
	insert_pending_groups(group_size);
	std::cout << "After insertion:" << std::endl;
	print_chains(group_size, false);
	for (size_t i = 0; i < this->_main_chain.size(); i++)
	{
		pos = this->_main_chain[i];
		for (size_t j = 0; j < group_size; j++)
			sorted.push_back(this->_nbrs[pos + j]);
	}
	this->_nbrs = sorted;
	std::cout << "\nVector reordered:" << std::endl;
	print_nbrs(block_size);
}
