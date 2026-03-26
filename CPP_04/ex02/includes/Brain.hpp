/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:32:02 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/26 13:49:58 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain(void);
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		~Brain(void);

		std::string getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
};

#endif
