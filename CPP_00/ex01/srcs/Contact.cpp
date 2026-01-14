/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:09:39 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/14 16:48:13 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void Contact::setFirstName(std::string value)
{
	this->firstName = value;
}
void Contact::setLastName(std::string value)
{
	this->lastName = value;
}
void Contact::setNickName(std::string value)
{
	this->nickName = value;
}
void Contact::setPhoneNumber(std::string value)
{
	this->phoneNumber = value;
}
void Contact::setDarkestSecret(std::string value)
{
	this->darkestSecret = value;
}

std::string Contact::getFirstName()
{
	return (this->firstName);
}
std::string Contact::getLastName()
{
	return (this->lastName);
}
std::string Contact::getNickName()
{
	return (this->nickName);
}
std::string Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}
