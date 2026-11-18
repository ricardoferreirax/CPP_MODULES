/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:50:12 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/18 23:22:47 by rmedeiro         ###   ########.fr       */
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
	std::cout << "Index: ";
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
	std::cout << std::endl << std::endl;
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
	if (show_pairs)
		std::cout << "Main chain before: ";
	else
		std::cout << "Main chain after: ";
	for (size_t i = 0; i < this->_main_chain.size(); i++)
	{
		print_group(this->_main_chain[i]);
		std::cout << " ";
	}
	std::cout << std::endl;
}

// Every loser belongs to a pair: b1 <= a1, b2 <= a2, b3 <= a3
// Since loser cannot be greater than its associated winner, we need to search before winner.
// Limit represents winner's curr idx -> binary search uses range [0, limit[.
// The function returns pos where loser should be inserted to keep main chain ordered.
size_t PmergeMe::find_insert_pos(const t_group &loser, size_t limit) const
{
	size_t left;
	size_t right;
	size_t mid;
	int    mid_max;
	int    loser_max;

	left = 0;
	right = limit; // set limit to winner idx or if no winner set to chain size
	loser_max = loser.nbrs[loser.nbrs.size() - 1]; // get max nbr of loser group
	while (left < right) // continue till we find pos to insert loser group
	{
		mid = left + (right - left) / 2; // get mid idx of main chain
		mid_max = this->_main_chain[mid].nbrs[this->_main_chain[mid].nbrs.size() - 1]; // get max nbr of mid group
		if (loser_max < mid_max)
			right = mid; // belongs before mid->continue search in left half
		else
			left = mid + 1; // belongs after mid->continue search in right half
	}
	return (left); // left is where loser should be inserted to keep main chain ordered
}

// J(n) = J(n-1) + 2*J(n-2), J(0) = 0, J(1) = 1  -> 0, 1, 1, 3, 5, 11, 21, 43, 85...
// jacobsthal determines limits of blocks of losers that we need to insert into main chain. 
// We insert each block backwards to reduce nbr of comparisons.
// we order winners: a1 < a2 < a3 and each loser is less than its associated winner: b1 < a1, b2 < a2, b3 < a3. 
// We have to insert b2 and b3. We have two options:
// 1) insert b2 first, we need to find before a2: b1 a1 | a2 a3 (in worst case we have 2 comparisons).
//    After inserting b2, we have to insert b3: b1 a1 b2 a2 | a3 (in worst case we have 3 comparisons).
// 2) insert b3 first, we need to find before a3: b1 a1 a2 | a3 (in worst case we have 2 comparisons).
//    After inserting b3, we have to insert b2: b1 a1 | a2 b3 a3 (in worst case we have 2 comparisons).
// For this, ford johnson uses b3 -> b2 insertion order.
std::vector<size_t> PmergeMe::jacobsthal_order() const
{
	std::vector<size_t> order; // losers idxs in jacobsthal insertion order
	size_t prev; // J(n-2)
	size_t curr; // J(n-1)
	size_t next; // J(n)
	size_t end; // last nbr to process in curr block

	prev = 1; // J(2)
	curr = 3; // J(3)
	while (prev <= this->_losers.size()) // while there are pend losers
	{
		end = curr; // set end of curr block
		if (end > this->_losers.size() + 1) // last block may contain more losers than we have, we limit it to the last loser
			end = this->_losers.size() + 1;
		for (size_t i = end; i > prev; i--) // insert losers in reverse order to reduce nbr of comparisons
			order.push_back(i - 2);
		if (curr >= this->_losers.size() + 1) // we have processed all losers
			break ;
		next = curr + 2 * prev; // J(n) = J(n-1) + 2*J(n-2)
		prev = curr; // update prev to J(n-1)
		curr = next; // update curr to J(n)
	}
	return (order);
}

void PmergeMe::insert_pend_losers()
{
	std::vector<size_t> order;
	size_t 				limit;
	size_t 				insert_pos;
	size_t 				loser_idx;

	order = jacobsthal_order(); // get losers idxs -> [1, 0, 3, 2] means insert b3, b2, b5, b4.
	for (size_t i = 0; i < order.size(); i++) // process each loser in jacobsthal order
	{
		loser_idx = order[i]; // get next loser idx to insert
		limit = this->_main_chain.size(); // allow search in entire main chain
		for (size_t j = 0; j < this->_pairs.size(); j++)
		{
			if (this->_losers[loser_idx].id == this->_pairs[j].loser.id) // find pair that has the curr loser
			{
				for (size_t k = 0; k < this->_main_chain.size(); k++)
				{
					if (this->_main_chain[k].id == this->_pairs[j].winner.id) // once we find the pair, we locate winner in main chain
					{
						limit = k; // loser cannot be greater than its winner, we limit search to before winner
						break ;
					}
				}
				break ; // we found the pair->stop search
			}
		}
		insert_pos = find_insert_pos(this->_losers[loser_idx], limit); // find where to insert loser in main chain
		this->_main_chain.insert(this->_main_chain.begin() + insert_pos, this->_losers[loser_idx]);
	}
}

void PmergeMe::ford_johnson_sort(size_t group_len)
{
	std::vector<int> sorted; // sorted nbrs to rebuilt after inserting losers
	t_pair			 pair;
	t_group			 straggler; // group w/o an associated winner
	size_t			 pair_len; // nbr of int in two groups
	size_t			 pos; // starting pos in _nbrs
	size_t			 complete_groups;

	if (group_len == 0 || group_len > this->_nbrs.size() / 2)
		return ; // base case: there arent enough nbrs to form two groups of group_len
	pair_len = group_len * 2;
	complete_groups = this->_nbrs.size() / group_len;
	for (size_t i = 0; i < this->_nbrs.size() / pair_len; i++)
	{
		pos = i * pair_len; // starting pos of curr pair
		if (this->_nbrs[pos + group_len - 1] > this->_nbrs[pos + pair_len - 1]) // compare max of two groups
			swap_groups(pos, pos + group_len, group_len); // swap groups if left group is greater
	}
	print_nbrs(pair_len);
	ford_johnson_sort(pair_len);
	std::cout << "Returning recursion (group " << group_len << "):" << std::endl << std::endl;
	print_nbrs(group_len);
	this->_pairs.clear();
	this->_main_chain.clear();
	this->_losers.clear();
	for (size_t i = 0; i < this->_nbrs.size() / pair_len; i++) // create loser/winner pair for every two complete groups
	{
		pos = i * pair_len;
		pair.pair_id = i;
		pair.loser = create_group(pos, group_len); // left group is loser (b1, b2, b3,...)
		pair.winner = create_group(pos + group_len, group_len); // right group is winner (a1, a2, a3,...)
		this->_pairs.push_back(pair); // store pair for find winner associated with loser
		if (i == 0)
			this->_main_chain.push_back(pair.loser); // first loser (b1) is inserted in main chain
		else
			this->_losers.push_back(pair.loser); // remaining losers (b2, b3,...) are stored in losers vector
		this->_main_chain.push_back(pair.winner); // add every winner to main chain 
	}
	if (complete_groups % 2 != 0) // nbr of complete groups is odd, last group cannot form a pair (straggler)
	{
		pos = (complete_groups - 1) * group_len; // find start of last complete group
		straggler = create_group(pos, group_len);
		this->_losers.push_back(straggler); // add straggler to losers vector
	}
	print_chains(true);
	insert_pend_losers(); // insert pend losers in main chain using jacobsthal order
	print_chains(false);
	for (size_t i = 0; i < this->_main_chain.size(); i++) // rebuild _nbrs with new group order
	{
		for (size_t j = 0; j < this->_main_chain[i].nbrs.size(); j++)
			sorted.push_back(this->_main_chain[i].nbrs[j]); // copy every nbr from curr group
	}
	for (size_t i = complete_groups * group_len; i < this->_nbrs.size(); i++)
		sorted.push_back(this->_nbrs[i]); // copy remaining nbrs that couldnt form a complete group
	this->_nbrs = sorted;
	std::cout << "\nrebuilt vector (group " << group_len << "):" << std::endl;
	print_nbrs(group_len);
}
