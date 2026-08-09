/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:50:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 20:54:55 by rmedeiro         ###   ########.fr       */
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
