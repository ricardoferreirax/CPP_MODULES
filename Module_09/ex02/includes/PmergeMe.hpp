/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:48:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/14 12:11:21 by rmedeiro         ###   ########.fr       */
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
		
		void	swap_groups(size_t first, size_t second, size_t group_size);
		void	compare_groups(size_t group_size);
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	validate_input(int ac, char **av);
		void	print_nbrs() const;
		void	sort_nbrs();
};

#endif
