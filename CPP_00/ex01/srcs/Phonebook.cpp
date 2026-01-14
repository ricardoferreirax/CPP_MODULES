/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:12:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/14 15:15:47 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// Constructor
PhoneBook::PhoneBook() : totalContacts(0) {}

// PhoneBook getters/setters
void PhoneBook::incrementTotalContacts() 
{ 
	this->totalContacts++; 
}

int PhoneBook::getMaxContacts() const 
{ 
	return this->maxContacts; 
}
int PhoneBook::getTotalContacts() const 
{ 
	return this->totalContacts; 
}

// Format helper
std::string PhoneBook::formatField(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return (str);
}

// Add contact
void PhoneBook::addContact(const Contact &contact)
{
    contacts[getTotalContacts() % getMaxContacts()] = contact;
    incrementTotalContacts();
}

// Display single contact by index
void PhoneBook::searchContact(int index) const
{
    if (index < 0 || index >= getTotalContacts() || index >= getMaxContacts())
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

// Display all contacts table
bool PhoneBook::displayAllContacts() const
{
    int count = getTotalContacts();
    if (count <= 0)
    {
        std::cout << "There are no contacts to display!" << std::endl;
        return (false);
    }
    if (count > getMaxContacts())
        count = getMaxContacts();
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "|     Index|First Name| Last Name| Nickname |" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << "|" << std::setw(10) << i
                  << "|" << std::setw(10) << formatField(contacts[i].getFirstName())
                  << "|" << std::setw(10) << formatField(contacts[i].getLastName())
                  << "|" << std::setw(10) << formatField(contacts[i].getNickName())
                  << "|" << std::endl;
    }
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    return (true);
}
