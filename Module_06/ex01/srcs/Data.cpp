/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 19:43:21 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/08 19:56:14 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data(void) : _name("Default"), _age(0)
{
	std::cout << "[Data] Default Data created!" << std::endl;
}

Data::Data(const std::string name, int age) : _name(name), _age(age)
{
	std::cout << "[Data] Data created!" << std::endl;
}

Data::Data(const Data &other) : _name(other._name), _age(other._age)
{
	std::cout << "[Data] Data copied to " << this->_name << "!" << std::endl;
}

Data &Data::operator=(const Data &other)
{
	std::cout << "[Data] Data assigned to " << this->_name << " and age: " << this->_age << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_age = other._age;
	}
	return (*this);
}

Data::~Data(void)
{
	std::cout << "[Data] Data destroyed!" << std::endl;
}

const std::string &Data::getName(void) const
{
	return (this->_name);
}

int Data::getAge(void) const
{
	return (this->_age);
}

void Data::setName(const std::string &name)
{
	this->_name = name;
}

void Data::setAge(int age)
{
	this->_age = age;
}

// struct Data
// {
// 	std::string name;
// 	int age;
// };
