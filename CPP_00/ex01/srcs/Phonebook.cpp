/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:12:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/14 16:14:30 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->totalContacts = 0;
}

void PhoneBook::incrementTotalContacts()
{
	this->totalContacts++;
}

int PhoneBook::getMaxContacts() const
{
	return (PhoneBook::maxContacts);
}
int PhoneBook::getTotalContacts() const
{
	return (this->totalContacts);
}

std::string PhoneBook::formatField(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::addContact(Contact contact)
{
	int	slot;

	slot = this->getTotalContacts() % this->getMaxContacts();
	this->contacts[slot] = contact;
	this->incrementTotalContacts();
}

void PhoneBook::searchContact(int index)
{
	int	count;

	count = this->getTotalContacts();
	if (count > this->getMaxContacts())
		count = this->getMaxContacts();
	if (index < 0 || index >= count)
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	std::cout << "\nFull contact information:" << std::endl;
	std::cout << "First Name    : " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name     : " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname      : " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number  : " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

bool PhoneBook::displayAllContacts()
{
	int count = this->getTotalContacts();
	if (count <= 0)
	{
		std::cout << "There are no contacts to display!" << std::endl;
		return (false);
	}
	if (count > this->getMaxContacts())
		count = this->getMaxContacts();
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name| Nickname |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < count; i++)
		std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << formatField(contacts[i].getFirstName()) << "|" << std::setw(10) << formatField(contacts[i].getLastName()) << "|" << std::setw(10) << formatField(contacts[i].getNickName()) << "|" << std::endl;

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	return (true);
}
