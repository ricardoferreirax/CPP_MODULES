/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:48:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/15 20:44:17 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <climits>
#include <exception>
#include <vector>

class	PmergeMe
{
	private:
		std::vector<int> _nbrs;
		std::vector<size_t> _main_chain; // store main chain groups indexes
		std::vector<size_t> _pend_groups; // store pend groups indexes to be inserted in main chain
		
		void	swap_groups(size_t first, size_t second, size_t group_size);
		void 	print_chains(size_t group_size, bool show_pairs) const;
		void 	insert_pending_groups(size_t group_size);
		void 	reorder_groups(size_t group_size);
		
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	validate_input(int ac, char **av);
		void	print_nbrs(size_t group_size) const;
		void 	merge_insertion_sort(size_t group_size);
};

#endif
