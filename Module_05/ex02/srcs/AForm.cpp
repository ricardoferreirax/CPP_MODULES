/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 17:39:25 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/07 17:41:19 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(void) 
	: _name("Untitled"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "[AForm] Default form created!" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "[AForm] " << this->_name << " has been created!" << std::endl;
}

AForm::AForm(const AForm &other) 
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "[AForm] " << this->_name << " has been copied!" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other._signed;
	std::cout << "[AForm] Assignment completed!" << std::endl;
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

bool AForm::isSigned(void) const
{
	return (this->_signed);
}

int AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
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
		throw NotSignedException();
	if (executor.getGrade() > this->_executeGrade)
		throw GradeTooLowException();
	this->executeForm();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << " | Signed: ";
	if (form.isSigned())
		out << "Yes";
	else
		out << "No";
	out << " | Sign grade: " << form.getSignGrade();
	out << " | Execute grade: " << form.getExecuteGrade();
	return (out);
}
