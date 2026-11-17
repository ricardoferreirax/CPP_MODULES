/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:50:12 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/17 21:03:12 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe constructor called." << std::endl;
}

PmergeMe::PmergeMe(int ac, char **av)
{
	std::string input;
	int			nb;
	int			digit;

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
	this->_pairs = other._pairs;
	this->_main_chain = other._main_chain;
	this->_losers = other._losers;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_nbrs = other._nbrs;
		this->_pairs = other._pairs;
		this->_main_chain = other._main_chain;
		this->_losers = other._losers;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called." << std::endl;
}

void PmergeMe::swap_groups(size_t a, size_t b, size_t group_len)
{
	int	temp;

	for (size_t i = 0; i < group_len; ++i)
	{
		temp = this->_nbrs[a + i];
		this->_nbrs[a + i] = this->_nbrs[b + i];
		this->_nbrs[b + i] = temp;
	}
}

t_group PmergeMe::create_group(size_t pos, size_t group_len) const
{
	t_group group;

	group.id = pos;
	for (size_t i = 0; i < group_len; i++)
		group.nbrs.push_back(this->_nbrs[pos + i]);
	return (group);
}

void PmergeMe::print_nbrs(size_t group_len) const
{
	std::cout << "\nIndex: ";
	for (size_t i = 0; i < this->_nbrs.size(); i++)
	{
		if (group_len > 0 && i % group_len == 0)
			std::cout << " [";
		else
			std::cout << " ";
		std::cout << std::setw(2) << i;
		if (group_len > 0 && ((i + 1) % group_len == 0 || i == this->_nbrs.size() - 1))
			std::cout << "]";
	}
	std::cout << std::endl;
	std::cout << "Vector:";
	for (size_t i = 0; i < this->_nbrs.size(); i++)
	{
		if (group_len > 0 && i % group_len == 0)
			std::cout << " [";
		else
			std::cout << " ";
		std::cout << std::setw(2) << this->_nbrs[i];
		if (group_len > 0 && ((i + 1) % group_len == 0 || i == this->_nbrs.size() - 1))
			std::cout << "]";
	}
	std::cout << std::endl;
}

void PmergeMe::print_group(const t_group &group) const
{
	std::cout << "(" << group.id << ")[";
	for (size_t i = 0; i < group.nbrs.size(); i++)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << group.nbrs[i];
	}
	std::cout << "]";
}

// pending: b1  b2  b3  b4
// winner:  a1  a2  a3  a4
void PmergeMe::print_chains(bool show_pairs) const
{
	if (show_pairs)
	{
		for (size_t i = 0; i < this->_pairs.size(); i++)
		{
			std::cout << "Pair " << this->_pairs[i].pair_id << ": ";
			std::cout << "Loser ";
			print_group(this->_pairs[i].loser);
			std::cout << " | Winner ";
			print_group(this->_pairs[i].winner);
			std::cout << std::endl;
		}
		std::cout << "\nPend groups: ";
		for (size_t i = 0; i < this->_losers.size(); i++)
		{
			print_group(this->_losers[i]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Main chain: ";
	for (size_t i = 0; i < this->_main_chain.size(); i++)
	{
		print_group(this->_main_chain[i]);
		std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::insert_losers(size_t group_size)
{
	size_t pend_pos;
	size_t winner_pos;
	size_t left;
	size_t right;
	size_t mid;
	int    pend_max;
	int    mid_max;

	for (size_t i = 0; i < this->_pend_groups.size(); i++)
	{
		pend_pos = this->_pend_groups[i]; // starting index in _nbrs
		pend_max = this->_nbrs[pend_pos + group_size - 1]; // last element of pending group (max)
		winner_pos = pend_pos + group_size;
		left = 0;
		right = this->_main_chain.size();
		for (size_t j = 0; j < this->_main_chain.size(); j++)
		{
			if (this->_main_chain[j] == winner_pos) // find pos of winner group in main chain
			{
				right = j;
				break ;
			}
		}
		while (left < right)
		{
			mid = left + (right - left) / 2; // find mid pos of main chain
			mid_max = this->_nbrs[this->_main_chain[mid] + group_size - 1]; // max value at mid pos of main chain
			if (pend_max < mid_max)
				right = mid; // search left half
			else
				left = mid + 1; // search right half
		}
		this->_main_chain.insert(this->_main_chain.begin() + left, pend_pos);
	}
}

void PmergeMe::ford_johnson_sort(size_t group_len)
{
	std::vector<int> sorted;
	t_pair 			 pair;
	size_t 			 pair_len; // len of two groups combined
	size_t 			 pos;
	size_t 			 total_groups;

	if (group_len == 0 || group_len > this->_nbrs.size() / 2)
		return ;
	pair_len = group_len * 2;
	total_groups = this->_nbrs.size() / group_len;
	for (size_t i = 0; i < this->_nbrs.size() / pair_len; i++)
	{
		pos = i * pair_len;
		if (this->_nbrs[pos + group_len - 1] > this->_nbrs[pos + pair_len - 1])
			swap_groups(pos, pos + group_len, group_len);
	}
	ford_johnson_sort(pair_len);
	this->_pairs.clear();
	this->_main_chain.clear();
	this->_losers.clear();
	for (size_t i = 0; i < this->_nbrs.size() / pair_len; i++)
	{
		pos = i * pair_len;
		pair.pair_id = i;
		pair.loser = make_group(pos, group_len);
		pair.winner = make_group(pos + group_len, group_len);
		this->_pairs.push_back(pair);
		if (i == 0)
			this->_main_chain.push_back(pair.loser);
		else
			this->_losers.push_back(pair.loser);
		this->_main_chain.push_back(pair.winner);
	}
	if (total_groups % 2 != 0)
	{
		pos = (total_groups - 1) * group_len;
		this->_losers.push_back(make_group(pos, group_len));
	}
	insert_losers();
	for (size_t i = 0; i < this->_main_chain.size(); i++)
	{
		for (size_t j = 0; j < this->_main_chain[i].nbrs.size(); j++)
			sorted.push_back(this->_main_chain[i].nbrs[j]);
	}
	for (size_t i = total_groups * group_len; i < this->_nbrs.size(); i++)
		sorted.push_back(this->_nbrs[i]);
	this->_nbrs = sorted;
}
