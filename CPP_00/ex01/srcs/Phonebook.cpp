/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:12:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/26 15:18:40 by rmedeiro         ###   ########.fr       */
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

std::string PhoneBook::_formatField(const std::string &s)
{
	if (s.length() > 10)
		return (s.substr(0, 9) + ".");
	return (std::string(10 - s.length(), ' ') + s);
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

int PhoneBook::_validateName(std::string s)
{
	int i;
	int letters;

	if (s.empty())
		return (1);
	if (s[0] < 'A' || s[0] > 'Z')
		return (1);
	i = 0;
	letters = 0;
	while (i < (int)s.length())
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') ||
		    (s[i] >= 'a' && s[i] <= 'z'))
			letters++;
		else if (s[i] != ' ')
			return (1);
		i++;
	}
	if (letters == 0)
		return (1);
	return (0);
}

int PhoneBook::_validatePhoneDigits(std::string s)
{
	int i;
	int digitCount;

	if (s.empty())
		return (1);
	i = 0;
	digitCount = 0;
	while (i < (int)s.length())
	{
		if (s[i] >= '0' && s[i] <= '9')
			digitCount++;
		else if (s[i] != ' ')
			return (1);
		i++;
	}
	if (digitCount < 9)
		return (1);
	return (0);
}

void PhoneBook::addContact(void)
{
	std::string first, last, nick, phone, secret;

	std::cout << "\nFirst name: ";
	if (!std::getline(std::cin, first))
		return ;
	while (this->_validateName(first) == 1)
	{
		std::cout << "\nInvalid input! This field:\n\n" << "-> Cannot be empty\n" << "-> Must start with a capital letter\n";
		std::cout << "-> Must contain only letters and spaces!\n\n" << "Try again!\n\n";
		std::cout << "First name: ";
		if (!std::getline(std::cin, first))
			return ;
	}
	this->_contacts[this->_lastAdded].setFirstName(first);

	std::cout << "Last name: ";
	if (!std::getline(std::cin, last))
		return ;
	while (this->_validateName(last) == 1)
	{
		std::cout << "\nInvalid input! This field:\n\n" << "-> Cannot be empty\n" << "-> Must start with a capital letter\n";
		std::cout << "-> Must contain only letters and spaces!\n\n" << "Try again!\n\n";
		std::cout << "Last name: ";
		if (!std::getline(std::cin, last))
			return ;
	}
	this->_contacts[this->_lastAdded].setLastName(last);

	std::cout << "Nickname: ";
	if (!std::getline(std::cin, nick))
		return ;
	while (this->_validateText(nick) == 1)
	{
		std::cout << "\nInvalid input! This field:\n\n" << "-> Cannot be empty\n\n" << "Try again!\n\n";
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, nick))
			return ;
	}
	this->_contacts[this->_lastAdded].setNickName(nick);
	
	std::cout << "Phone number: ";
	if (!std::getline(std::cin, phone))
		return ;
	while (this->_validatePhoneDigits(phone) == 1)
	{
		std::cout << "\nInvalid input! This field:\n\n" << "-> Cannot be empty\n" << "-> Must contain at least 9 digits\n\n" << "Try again!\n\n";
		std::cout << "Phone number: ";
		if (!std::getline(std::cin, phone))
			return ;
	}
	this->_contacts[this->_lastAdded].setPhoneNumber(phone);
	
	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, secret))
		return ;
	while (this->_validateText(secret) == 1)
	{
		std::cout << "\nInvalid input! This field:\n\n" << "-> Cannot be empty\n\n" << "Try again!\n\n";
		std::cout << "Darkest secret: ";
		if (!std::getline(std::cin, secret))
			return ;
	}
	this->_contacts[this->_lastAdded].setDarkestSecret(secret);

	if (this->_totalContacts < 8)
		this->_totalContacts++;

	this->_lastAdded++;
	if (this->_lastAdded == 8)
		this->_lastAdded = 0;

	std::cout << "\nContact saved!\n\n";
	if (this->_totalContacts == 8)
		std::cout << "PhoneBook is full: new contacts will replace the oldest one.\n";
}

int PhoneBook::displayAllContacts(void)
{
	int i;

	if (this->_totalContacts == 0)
	{
		std::cout << "\nThere are no contacts to display!\n" << std::endl;
		return (0);
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	i = 0;
	while (i < this->_totalContacts && i < 8)
	{
		std::cout << "|" << std::setw(10) << i
		          << "|" << _formatField(this->_contacts[i].getFirstName())
		          << "|" << _formatField(this->_contacts[i].getLastName())
		          << "|" << _formatField(this->_contacts[i].getNickName())
		          << "|" << std::endl;
		i++;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	return (1);
}

void PhoneBook::searchContacts(void)
{
	std::string input;
	int i;

	if (this->displayAllContacts() == 0)
		return ;
	std::cout << "\nEnter index: ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "\nInvalid index!" << std::endl;
		return ;
	}
	i = input[0] - '0';
	if (i >= this->_totalContacts)
	{
		std::cout << "\nIndex does not exist!" << std::endl;
		return;
	}
	this->_contacts[i].displayContact();
}
