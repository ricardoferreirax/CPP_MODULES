/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:30:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/12 16:39:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// Creates a Bureaucrat with a default name and grade 150. Grade 150 is the lowest grade
Bureaucrat::Bureaucrat(void)
	: _name("Default"), _grade(150)
{
	std::cout << "[Bureaucrat] Default bureaucrat created!" << std::endl;
}

//  Creates a Bureaucrat using a custom name and grade.
Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "[Bureaucrat] " << this->_name << " has been created with grade " << this->_grade << "!" << std::endl;
}

// Creates a new Bureaucrat from an already existing Bureaucrat object. Both the name and grade are copied during construction.
Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << "[Bureaucrat] A copy of " << other._name << " has been created!" << std::endl;
}

//  Copies the assignable state of another Bureaucrat into an object that already exists.
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << "[Bureaucrat] Grade assigned to " << this->_name << "!" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "[Bureaucrat] " << this->_name << " has been destroyed!" << std::endl;
}

// Returns the Bureaucrat's name. It returns const std::string& instead of std::string in order to avoid
// creating an unnecessary copy of the string. The returned reference is const so the caller cannot modify 
// the name through the getter.
const std::string &Bureaucrat::getName(void) const
{
	return (this->_name);
}

// Returns the Bureaucrat's current grade. The final const means this function does not modify the object.
int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// Increases the Bureaucrat's grade by decrementing it by 1. If the grade is already at the maximum (1) or lower, it throws a GradeTooHighException.
void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

// Decreases the Bureaucrat's grade by incrementing it by 1. If the grade is already at the minimum (150) or greater, it throws a GradeTooLowException.
void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

// Returns a string associated with a grade higher than the allowed rank (less than 1). Overrides the what() from std::exception and
// it will still be called because std::exception uses polymorphism
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat grade cannot be higher than 1!");
}

// Returns a string associated with a grade lower than the allowed rank (greater than 150). Overrides the what() from std::exception and 
// it will still be called because std::exception uses polymorphism
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat grade cannot be lower than 150!");
}

// Stream insertion operator, overload for a Bureaucrat object to an output stream. It allows to use the << operator to print the Bureaucrat's 
// name and grade in a formatted way.
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << " | Grade: " << bureaucrat.getGrade();
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

