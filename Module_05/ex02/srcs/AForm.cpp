/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:27:34 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/03 15:30:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(void) : _name("Default"), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
	this->_isSigned = false;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExecute)
	: _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << "AForm constructor called" << std::endl;
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	this->_isSigned = false;
}

AForm::AForm(const AForm &src) : _name(src._name), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
	this->_isSigned = src._isSigned;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &src)
		this->_isSigned = src._isSigned;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

const std::string &AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int AForm::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (this->_isSigned == false)
		throw NotSignedException();
	if (executor.getGrade() > this->_gradeExecute)
		throw GradeTooLowException();
	this->executeAction();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm grade is too high");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm grade is too low");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("AForm is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm name: " << form.getName() << std::endl;
	out << "Signed: ";
	if (form.getIsSigned())
		out << "Yes";
	else
		out << "No";
	out << std::endl;
	out << "Grade required to sign: " << form.getGradeSign() << std::endl;
	out << "Grade required to execute: " << form.getGradeExecute() << std::endl;
	return (out);
}
