/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:12:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/07 23:53:28 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Phonebook.hpp"

PhoneBook::PhoneBook(void) : _totalContacts(0), _lastAdded(0) 
{
	std::cout << "PhoneBook created!\n" << std::endl;
}

PhoneBook::~PhoneBook(void) 
{
	std::cout << "PhoneBook destroyed!" << std::endl;
}

int PhoneBook::_validateText(const std::string s)
{
	int i;
	int spaces;

	if (s.empty())
		return (1);
	i = 0;
	spaces = 0;
	while (i < (int)s.length())
	{
		if (s[i] < 32 || s[i] > 126)
			return (1);
		if (s[i] == ' ')
			spaces++;
		i++;
	}
	if (spaces == (int)s.length())
		return (1);
	return (0);
}

int PhoneBook::_validatePhoneDigits(std::string s)
{
	int i;

	if (s.empty())
		return (1);
	i = 0;
	while (i < (int)s.length())
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void PhoneBook::addContact(void)
{
	std::string first, last, nick, phone, secret;

	std::cout << "First name: ";
	if (!std::getline(std::cin, first))
		return ;
	while (this->_validateText(first) == 1)
	{
		std::cout << "First name cannot be empty! Please try again!\n";
		std::cout << "First name: ";
		if (!std::getline(std::cin, first))
			return ;
	}

	std::cout << "Last name: ";
	if (!std::getline(std::cin, last))
		return ;
	while (this->_validateText(last) == 1)
	{
		std::cout << "Last name cannot be empty! Please try again!\n";
		std::cout << "Last name: ";
		if (!std::getline(std::cin, last))
			return ;
	}

	std::cout << "Nickname: ";
	if (!std::getline(std::cin, nick))
		return ;
	while (this->_validateText(nick) == 1)
	{
		std::cout << "Nickname cannot be empty! Please try again!\n";
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, nick))
			return ;
	}

	std::cout << "Phone number: ";
	if (!std::getline(std::cin, phone))
		return ;
	while (this->_validatePhoneDigits(phone) == 1)
	{
		std::cout << "Phone number must contain digits only! Try again!\n";
		std::cout << "Phone number: ";
		if (!std::getline(std::cin, phone))
			return ;
	}

	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, secret))
		return ;
	while (this->_validateText(secret) == 1)
	{
		std::cout << "Darkest secret cannot be empty! Please try again!\n";
		std::cout << "Darkest secret: ";
		if (!std::getline(std::cin, secret))
			return ;
	}

	this->_contacts[this->_lastAdded].setFirstName(first);
	this->_contacts[this->_lastAdded].setLastName(last);
	this->_contacts[this->_lastAdded].setNickName(nick);
	this->_contacts[this->_lastAdded].setPhoneNumber(phone);
	this->_contacts[this->_lastAdded].setDarkestSecret(secret);

	if (this->_totalContacts < 8)
		this->_totalContacts++;

	this->_lastAdded++;
	if (this->_lastAdded == 8)
		this->_lastAdded = 0;

	std::cout << "Contact saved!\n";
	if (this->_totalContacts == 8)
		std::cout << "PhoneBook is full: new contacts will replace the oldest one.\n";
}


void PhoneBook::searchContacts(void)
{
	if (this->_totalContacts == 0)
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < this->_totalContacts; i++)
		this->_contacts[i].printRow(i);

	std::string input;
	int i;

	std::cout << "Enter index: ";
	if (!std::getline(std::cin, input))
		return;

	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}

	i = input[0] - '0';
	if (i >= this->_totalContacts)
	{
		std::cout << "Index does not exist" << std::endl;
		return;
	}
	this->_contacts[i].displayContact();
}
