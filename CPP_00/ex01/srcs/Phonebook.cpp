/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:12:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/07 22:20:54 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Phonebook.hpp"

PhoneBook::PhoneBook(void) : _contactCount(0), _nextIndex(0) 
{
	std::cout << "PhoneBook created!" << std::endl;
}

PhoneBook::~PhoneBook(void) 
{
	std::cout << "PhoneBook destroyed!" << std::endl;
}

int PhoneBook::_validateText(const std::string &s) const
{
	int i = 0;
	int spaces = 0;

	if (s.empty())
		return (1);
	while (i < s.length())
	{
		if (!std::isprint(s[i]))
			return (1);
		if (std::isspace(s[i]))
			spaces++;
		i++;
	}
	if (spaces == s.length())
		return (1);
	return (0);
}
