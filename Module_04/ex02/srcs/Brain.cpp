/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:34:36 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/28 15:56:14 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor created!" << std::endl;
}

// copies all the 100 ideias from the src Brain into current. 
// Each idea string is copied individually to ensure that the new Brain has its own 
// copy of the ideas, rather than just copying the pointer.
Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	std::cout << "Brain copy constructor created!" << std::endl;
}

// deep copy: the new Brain will have its own separate memory for the ideas and its changes
// in one Brain will not affect the other Brain.
Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain copy assignment operator created!" << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructed!" << std::endl;
}

// returns the idea stored at the specified index in the _ideas array
std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (this->_ideas[index]);
}

// sets/stores the new ideia in requested index of the _ideas array
void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100)
		return ;
	this->_ideas[index] = idea;
}
