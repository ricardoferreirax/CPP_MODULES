/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:09:39 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/31 14:53:11 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void)
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
	std::cout << "Contact created!" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact destroyed!" << std::endl;
}

void Contact::setFirstName(std::string &firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(std::string &lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickName(std::string &nickName)
{
	this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string &phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string &darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNickName(void) const
{
	return (this->_nickName);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

// Display all contact's details
void Contact::displayContact(void)
{
	std::cout << "\nFirst Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}
