/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:24:05 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/07/28 18:03:26 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form(void) : _name("Default"), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
	this->_isSigned = false;
}

Form::Form(const std::string name, int gradeSign, int gradeExecute) 
	: _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	this->_isSigned = false;
}

Form::Form(const Form &src) : _name(src._name), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	this->_isSigned = src._isSigned;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &src)
		this->_isSigned = src._isSigned;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade is too high. Max grade is 1");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade is too low. Min grade is 150");
}

bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int Form::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form name: " << form.getName() << std::endl;
	out << "Signed: ";
	if (form.getIsSigned())
		out << "Yes";
	else
		out << "No";
	out << std::endl;
	out << "Grade required to sign: " << form.getGradeSign() << std::endl;
	out << "Grade required to execute: " << form.getGradeExecute();
	return (out);
}
