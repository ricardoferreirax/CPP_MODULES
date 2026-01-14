/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:23:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/14 16:14:00 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
#include "../includes/Contact.hpp"

class PhoneBook
{
  private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int totalContacts;

  public:
    PhoneBook();

    void incrementTotalContacts();
    int getMaxContacts() const;
    int getTotalContacts() const;

    std::string formatField(std::string str);
    void addContact(Contact contact);
    void searchContact(int index);
    bool displayAllContacts();
};

#endif