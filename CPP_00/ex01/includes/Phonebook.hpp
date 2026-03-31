/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:23:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/30 14:39:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

// store and manage several contacts
class PhoneBook
{
	private:
    Contact _contacts[8];
    int _totalContacts;
    int _lastAdded;

    int _validateText(std::string s);
	int _validatePhoneDigits(std::string s);
	int _validateName(std::string s);
	std::string _formatField(const std::string &s);
	public:
    	PhoneBook( void );
    	~PhoneBook( void );

    	void addContact( void );
    	void searchContacts( void );
		int displayAllContacts(void);
};

#endif