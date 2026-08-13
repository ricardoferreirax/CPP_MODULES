/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:48:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/13 18:32:27 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

// Creates a default Form that is not signed. Both required grades are initialized 
// to 150, which is the lowest valid grade.
Form::Form(void)
	: _name("Untitled form"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "[Form] Form has been created!" << std::endl;
}

Form::Form(const std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "[Form] " << this->_name << " has been created and is waiting for a signature!" << std::endl;
}

// Creates a new Form as an exact copy with the same name, signature state and grade as another Form.
// It is called when a new object is initialized from an existing object.
Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "[Form] A copy of " << other._name << " has been created!" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;
	std::cout << "[Form] Signature copied into " << this->_name << "." << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "[Form] " << this->_name << " has been destroyed!" << std::endl;
}

// Returns the Form's name as a const reference in order to avoid the caller to modify the object's name.
const std::string &Form::getName(void) const
{
	return (this->_name);
}

// Returns the minimum Bureaucrat grade required to sign the Form. The final const means this function does not modify the object.
int Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

// Returns the current signature state of the Form. True if the Form is signed, false otherwise.
bool Form::isSigned(void) const
{
	return (this->_signed);
}

// This custom exception inherits from std::exception and provides its own implementation of what().
// what() overrides the virtual function from std::exception and provides a descriptive message explaining why the exception was thrown.
const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("A form cannot require a grade higher than 1!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("The bureaucrat does not have the required grade!");
}

// Attempts to sign the Form with the given Bureaucrat. The Bureaucrat grade is compared with the Form's required 
// signing grade. Since grade 1 is the highest rank, a numerically greater grade means a lower-ranked Bureaucrat.
// If the Bureaucrat does not have a sufficient grade, GradeTooLowException is thrown and the Form remains unsigned.
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

//Allows a Form object to be printed directly with std::cout. It prints the Form name, signature state, required signing 
// grade and required execution grade.
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " | Signature: ";
	if (form.isSigned())
		out << "Present";
	else
		out << "Missing";
	out << " | Sign grade: " << form.getSignGrade() << " | Execute grade: " << form.getExecuteGrade();
	return (out);
}


 // Bureaucrat::signForm() -> asks a Form to be signed by the current Bureaucrat. Belongs to the Bureaucrat class 
 // because it represents an action performed by a Bureaucrat: trying to sign a Form.
 //
 // Form::beSigned() -> decides whether that Bureaucrat actually has permission to sign it. This function contains 
 // the rules that must be satisfied before the Form can become signed. It receives the Bureaucrat that is trying to sign the Form.