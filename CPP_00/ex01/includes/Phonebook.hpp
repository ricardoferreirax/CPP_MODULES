/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:23:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/14 16:43:40 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "../includes/Contact.hpp"

class PhoneBook
{
  private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int totalContacts;

  public:
    // 
    PhoneBook();

    void updateContactCount();
    int getMaxContacts() const;
    int getTotalContacts() const;

    std::string truncateForDisplay(std::string field);
    void storeContact(Contact contact);
    void printContactDetails(int index);
    bool printContactsTable();
};

#endif