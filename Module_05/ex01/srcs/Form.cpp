/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:40:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/05 15:53:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form(void) : _name("Untitled form"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "[Form] A blank form has been prepared!" << std::endl;
}

Form::Form(const std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "[Form] \"" << this->_name << "\" has been prepared and is waiting for a signature!" << std::endl;
}

Form::Form(const Form &other) 
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "[Form] A copy of \"" << other._name << "\" has been created!" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;
	std::cout << "[Form] Signature copied into \"" << this->_name << "\"!" << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "[Form] \"" << this->_name << "\" has been destroyed!" << std::endl;
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
	return ("A form cannot require a grade higher than 1!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("The bureaucrat does not have the required grade!");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "\"" << form.getName() << "\"" << " | Signature: ";
	if (form.isSigned())
		out << "Present";
	else
		out << "Missing";
	out << " | Sign grade: "
		<< form.getSignGrade()
		<< " | Execute grade: "
		<< form.getExecuteGrade();
	return (out);
}
