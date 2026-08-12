/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:30:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/12 22:24:47 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// Creates a Bureaucrat with a default name and the lowest valid grade (150).
// The initializer list is used because _name is const and must be initialized during object construction.
Bureaucrat::Bureaucrat(void)
	: _name("Default"), _grade(150)
{
	std::cout << "[Bureaucrat] Default bureaucrat created!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "[Bureaucrat] " << this->_name << " has been created with grade " << this->_grade << "!" << std::endl;
}

// Creates a new Bureaucrat as an exact copy of another one. It is called when a new object is initialized from an existing object.
Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << "[Bureaucrat] A copy of " << other._name << " has been created!" << std::endl;
}

// Copies the assignable state of another Bureaucrat into an existing object.
// The name is not copied because _name is const and cannot be modified after construction.
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

// Returns the Bureaucrat's name as a const reference in order to avoid the caller to modify the object's name.
const std::string &Bureaucrat::getName(void) const
{
	return (this->_name);
}

// Returns the Bureaucrat's current grade. The final const means this function does not modify the object.
int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// Promotes the Bureaucrat. Since grade 1 is the highest rank, promoting a Bureaucrat decreases the numeric value 
// of the grade. If the Bureaucrat is already at grade 1, a GradeTooHighException is thrown.
void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

// Demotes the Bureaucrat. Since grade 150 is the lowest rank, demoting a Bureaucrat increases the numeric value 
// of the grade. If the Bureaucrat is already at grade 150, a GradeTooLowException is thrown.
void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

// This function overrides std::exception::what() and provides a descriptive message explaining why the exception was thrown.
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat grade cannot be higher than 1!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat grade cannot be lower than 150!");
}

// Stream insertion operator allows a Bureaucrat object to be printed using std::cout. It returns the output stream by 
// reference so multiple << operations can be chained together.
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << " | Grade: " << bureaucrat.getGrade();
	return (out);
}

/*
 * Exception: is an object that represents an runtime error or an unexpected situation that
 * occurs during the execution of a program. When an exception is thrown, the normal execution 
 * flow is interrupted and control is transferred to the nearest compatible catch block.
 * ---------------------------------------------------------------------
 * Throw: is used to signal an exception when a problem occurs. The thrown object is an instance 
 * of a class derived from std::exception. When a throw statement is executed, the following happens:
 * 1. An exception object is created.
 * 2. Normal execution immediately stops.
 * 3. The program starts searching for a matching catch block.
 * ---------------------------------------------------------------------
 * try: defines a block of code that will be tested for exceptions.
 * If no exception occurs, execution reaches the end of the try block. If an exception is thrown 
 * inside the try block, execution stops immediately and jumps to the first catch block.
 * ---------------------------------------------------------------------
 * catch: defines a block that receives and handles an exception previously thrown inside
 * the associated try block.
 * ---------------------------------------------------------------------
 * std::exception: is the standard base class for exceptions in C++.
 * By inheriting from std::exception, custom exceptions automatically become
 * compatible with generic catch blocks. This allows many different exception types to be handled 
 * through the same interface.
 * ---------------------------------------------------------------------
 * what(): is a virtual member function inherited from std::exception. Every custom exception overrides 
 * this function in order to provide a meaningful error message. It returns a C-style string that describes 
 * the exception. Because what() is virtual, the correct overridden version is selected at runtime through polymorphism.
 */
 