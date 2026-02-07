/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:21:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/07 22:17:07 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

		std::string _formatField(const std::string &content) const;
	public:
		Contact(void);
		~Contact(void);

		void setFirstName(std::string &firstName);
		void setLastName(std::string &lastName);
		void setNickName(std::string &nickName);
		void setPhoneNumber(std::string &phoneNumber);
		void setDarkestSecret(std::string &darkestSecret);

		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;

		void printRow(int index) const;
		void displayContact(void) const;
};

#endif