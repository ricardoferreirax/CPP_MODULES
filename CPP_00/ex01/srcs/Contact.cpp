/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:09:39 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/14 15:56:22 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// Setters
void Contact::setFirstName(const std::string &value) 
{ 
	this->firstName = value; 
}
void Contact::setLastName(const std::string &value)  
{ 
	this->lastName = value; 
}
void Contact::setNickName(const std::string &value)  
{ 
	this->nickName = value; 
}
void Contact::setPhoneNumber(const std::string &value) 
{ 
	this->phoneNumber = value; 
}
void Contact::setDarkestSecret(const std::string &value) 
{ 
	this->darkestSecret = value; 
}

// Getters
std::string Contact::getFirstName() const 
{ 
	return this->firstName; 
}
std::string Contact::getLastName()  const 
{ 
	return this->lastName; 
}
std::string Contact::getNickName()  const 
{ 
	return this->nickName; 
}
std::string Contact::getPhoneNumber() const 
{ 
	return this->phoneNumber; 
}
std::string Contact::getDarkestSecret() const 
{ 
	return this->darkestSecret; 
}
