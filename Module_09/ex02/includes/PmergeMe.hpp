/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:48:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/17 21:18:26 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <climits>
# include <cstddef>
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

typedef struct s_group
{
	std::vector<int> nbrs;
	size_t	id;
}			t_group;

typedef struct s_pair
{
	t_group	loser;
	t_group	winner;
	size_t	pair_id;
}			t_pair;

class PmergeMe
{
	private:
		std::vector<int>     _nbrs;
		std::vector<t_pair>  _pairs; // store pairs of groups
		std::vector<t_group> _main_chain; // store main chain groups idxs
		std::vector<t_group> _losers; // store losers groups idxs

		t_group create_group(size_t pos, size_t group_size) const;
		size_t 	find_insert_pos(const t_group &loser, size_t limit) const;
		void 	swap_groups(size_t first, size_t second, size_t group_size);
		void 	print_group(const t_group &group) const;
		void 	print_chains(bool show_pairs) const;
		void 	insert_pend_losers();
		void 	reorder_groups();

	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	validate_input(int ac, char **av);
		void	print_nbrs(size_t group_size) const;
		void	ford_johnson_sort(size_t group_size);
};

#endif
