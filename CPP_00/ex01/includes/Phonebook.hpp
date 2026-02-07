/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:23:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/06 23:51:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
    Contact _contacts[8];
    int _contactCount;
    int _oldestContact;

    std::string _truncateString(const std::string &str) const;
    void _displayContact(int index) const;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContacts() const;
};

#endif