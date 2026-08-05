/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:30:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/05 11:15:23 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Unnamed"), _grade(150)
{
	std::cout << "[Bureaucrat] A default bureaucrat has been created!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "[Bureaucrat] " << this->_name << " has been created with grade " << this->_grade << "!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "[Bureaucrat] Copied " << other._name << " with grade " << other._grade << "!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << "[Bureaucrat] Grade assignment completed." << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "[Bureaucrat] " << this->_name << " has been destroyed!" << std::endl;
}

const std::string &Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade 1 is already the highest possible grade!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade 150 is already the lowest possible grade!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << " is currently at grade " << bureaucrat.getGrade();
	return (out);
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

// When constructing a Bureaucrat with an invalid grade, the class must throw n appropriate 
// exception. Two custom exception types are implemented: - GradeTooHighException
// 														  - GradeTooLowException
// 
// The class also provides the member functions incrementGrade() and decrementGrade()
// which they must check whether the resulting grade remains within the valid range. 
// If not, the corresponding exception is thrown.
