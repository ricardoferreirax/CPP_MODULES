/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 04:25:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/27 18:26:34 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw ;
	else if (grade > 150)
		throw ;
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->_grade = src._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	std::cout << "Increment grade" << std::endl;
	if (this->_grade <= 1)
		throw ;
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	std::cout << "Decrement grade" << std::endl;
	if (this->_grade >= 150)
		throw ;
	this->_grade++;
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &src)
{
	output << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (output);
}

// try: Defines a block of code that will be tested for exceptions. 
// If an exception is thrown inside this block, control passes to the matching 
// catch block.

// throw: Used to signal (or "throw") an exception when a problem occurs. 
// The thrown object is typically an instance of a class derived from std::exception.

// catch: Defines a block of code that handles an exception. 
// It catches the thrown exception if its type matches or is compatible with the type 
// specified in the catch block.

// Exception: An exception is a runtime error or an unexpected event that occurs during 
// program execution.

// Exception Handling: A mechanism that allows a program to detect, catch, and handle 
// exceptions so that the program can continue executing or terminate instead of crashing.