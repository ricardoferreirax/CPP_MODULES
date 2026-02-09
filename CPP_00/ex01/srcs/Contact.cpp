/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:09:39 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/09 00:45:33 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
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

void Contact::displayContact(void)
{
	std::cout << "\nFirst Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}
