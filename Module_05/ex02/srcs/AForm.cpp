/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:50:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/17 12:32:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(void)
	: _name("Untitled"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "[AForm] A form has been created!" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "[AForm] " << this->_name << " has been created and is waiting for a signature!" << std::endl;
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "[AForm] A copy of " << other._name << " has been created!" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other._signed;
	std::cout << "[AForm] Signature copied into " << this->_name << "." << std::endl;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "[AForm] " << this->_name << " has been destroyed!" << std::endl;
}

const std::string &AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

bool AForm::isSigned(void) const
{
	return (this->_signed);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("A form cannot require a grade higher than 1!");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("The bureaucrat does not have the required grade!");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("The form has not been signed yet!");
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!this->_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_executeGrade)
		throw GradeTooLowException();
	this->processForm();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << " | Signature: ";
	if (form.isSigned())
		out << "Present";
	else
		out << "Missing";
	out << " | Sign grade: " << form.getSignGrade() << " | Execute grade: " << form.getExecuteGrade();
	return (out);
}


// AForm is the abstract version of Form. In ex01, Form is a concrete class and can be instantiated directly. In ex02, AForm becomes 
// the common base class for all specific forms, such as ShrubberyCreationForm, RobotomyRequestForm and PresidentialPardonForm.
// AForm stores the common data and common rules: name, signed state, signing grade, execution grade, beSigned() and execute(). 
// The derived classes only define what their specific action actually does.
// The main difference is that AForm does not know what the concrete action of a form should be. A shrubbery form must create a 
// file containing trees, a robotomy form must attempt a robotomy, and a presidential pardon form must print a pardon message. 
// Because AForm cannot provide one implementation that makes sense for all these cases, it declares a pure virtual function.
// The function processForm() is declared as pure virtual: virtual void processForm(void) const = 0; The "= 0" means that AForm does not 
// provide the concrete action and forces derived classes to implement it. Because AForm has a pure virtual function, it is an abstract
// class and cannot be instantiated directly. AForm therefore works as a common interface: it defines the rules that every form must
// follow, while each derived class provides its own processForm() implementation.
// AForm contains the common rules; derived forms contain the specific action.


// Runtime polymorphism allows a base-class reference or pointer to refer to different derived objects. When a virtual function is called through 
// that reference or pointer, C++ selects the correct overridden function according to the real type of the object at runtime.
// AForm provides the common interface and processForm() is virtual. Therefore, AForm::execute() can call processForm() without knowing the specific 
// form type. At runtime, C++ calls the implementation of the actual derived object, such as RobotomyRequestForm::processForm() or ShrubberyCreationForm::processForm().


// When AForm::execute() calls processForm(), C++ uses runtime polymorphism to choose which version of processForm() must be executed.
//
// Runtime polymorphism means that the function that will be called is decided at runtime according to the real type of the object, not 
// only according to the type of the pointer or reference used to access it. For example: AForm &form = robotomy;
// The reference "form" has the type AForm&, but the real object is a RobotomyRequestForm. If processForm() is virtual and we call:
// form.processForm(); C++ checks the real type of the object at runtime. Since the real object is a RobotomyRequestForm, it calls:
// RobotomyRequestForm::processForm(). The same AForm reference could refer to different derived objects: shrubbery, robotomy, or pardon.
// Calling the same virtual function on each reference can produce different behavior:
//
//     form1 -> ShrubberyCreationForm::processForm()
//     form2 -> RobotomyRequestForm::processForm()
//     form3 -> PresidentialPardonForm::processForm()
//
// This is runtime polymorphism: one common base-class interface can represent different derived objects, and virtual functions allow C++ to 
// select the correct implementation according to the real object type at runtime.
//
// In this exercise, AForm::execute() contains the common validation logic. It checks if the form is signed and if the Bureaucrat has the required 
// execution grade. If all checks succeed, execute() calls processForm(). Since processForm() is virtual, the specific action of the real derived 
// form is automatically executed.
