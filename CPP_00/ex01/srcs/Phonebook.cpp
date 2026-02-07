/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:12:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/07 22:37:08 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Phonebook.hpp"

PhoneBook::PhoneBook(void) : _totalContacts(0), _lastAdded(0) 
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

int PhoneBook::_validatePhoneDigits(std::string s)
{
	int i = 0;

	if (s.empty())
		return 1;
	while (i < (int)s.length())
	{
		if (!std::isdigit(s[i]))
			return 1;
		i++;
	}
	return 0;
}

void PhoneBook::addContact(void)
{
	std::string input;
	int i;

	i = this->_lastAdded;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (this->_validateText(input) != 0)
	{
		std::cout << "Contact cannot have empty fields." << std::endl;
		return ;
	}
	this->_contacts[i].setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (this->_validateText(input) != 0)
	{
		std::cout << "Contact cannot have empty fields." << std::endl;
		return ;
	}
	this->_contacts[i].setLastName(input);
	
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (this->_validateText(input) != 0)
	{
		std::cout << "Contact cannot have empty fields." << std::endl;
		return ;
	}
	this->_contacts[i].setNickName(input);

	std::cout << "Enter phone number (digits only): ";
	std::getline(std::cin, input);
	if (this->_validatePhoneDigits(input) != 0)
	{
		std::cout << "Error: phone number must contain only digits." << std::endl;
		return ;
	}
	this->_contacts[i].setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (this->_validateText(input) != 0)
	{
		std::cout << "Contact cannot have empty fields." << std::endl;
		return ;
	}
	this->_contacts[i].setDarkestSecret(input);

	this->_lastAdded++;
	if (this->_lastAdded >= 8)
		this->_lastAdded = 0;
	if (this->_totalContacts < 8)
		this->_totalContacts++;

	std::cout << "Contact added successfully!" << std::endl;
}
