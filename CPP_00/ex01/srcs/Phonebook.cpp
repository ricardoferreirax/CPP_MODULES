/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:12:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/14 16:44:13 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Phonebook.hpp"

// Initialize empty phonebook
PhoneBook::PhoneBook()
{
	totalContacts = 0;
}

// Increase total stored contacts
void PhoneBook::updateContactCount()
{
	totalContacts++;
}

// Return max capacity (8)
int PhoneBook::getMaxContacts() const
{
	return (maxContacts);
}

// Return total number of added contacts
int PhoneBook::getTotalContacts() const
{
	return (totalContacts);
}

// Truncate a field to fit 10 characters
std::string PhoneBook::truncateForDisplay(std::string field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

// Store a contact using circular buffer logic
void PhoneBook::storeContact(Contact contact)
{
	int	slot;

	slot = totalContacts % maxContacts;
	contacts[slot] = contact;
	updateContactCount();
}

// Print full information of one contact
void PhoneBook::printContactDetails(int index)
{
	int	visible;

	visible = totalContacts;
	if (visible > maxContacts)
		visible = maxContacts;
	if (index < 0 || index >= visible)
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

// Print contacts table (SEARCH view)
bool PhoneBook::printContactsTable()
{
	int	visible;

	visible = totalContacts;
	if (visible <= 0)
	{
		std::cout << "There are no contacts to display!" << std::endl;
		return (false);
	}
	if (visible > maxContacts)
		visible = maxContacts;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name| Nickname |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < visible; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << truncateForDisplay(contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << truncateForDisplay(contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << truncateForDisplay(contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	return (true);
}
