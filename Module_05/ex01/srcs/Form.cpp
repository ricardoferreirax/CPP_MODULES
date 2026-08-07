/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 17:58:19 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/07 17:59:41 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form(void)
	: _name("Untitled"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "[Form] Default form created!" << std::endl;
}

Form::Form(const std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "[Form] " << this->_name << " has been created!" << std::endl;
}

Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "[Form] " << this->_name << " has been copied!" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;
	std::cout << "[Form] Assignment completed!" << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "[Form] " << this->_name << " has been destroyed!" << std::endl;
}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

bool Form::isSigned(void) const
{
	return (this->_signed);
}

int Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
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
