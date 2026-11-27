/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:19:04 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/27 13:19:48 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _nbrs;
	
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
};

#endif
