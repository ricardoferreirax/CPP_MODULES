/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:51:54 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/13 16:05:08 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

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

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << "[Bureaucrat] A copy of " << other._name << " has been created!" << std::endl;
}

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

const std::string &Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat grade cannot be higher than 1!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat grade cannot be lower than 150!");
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();

	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();

	this->_grade++;
}

// Attempts to sign the form using the current Bureaucrat. "*this" means the current Bureaucrat object is passed by reference.
// If the Bureaucrat has a sufficient grade, beSigned() succeeds and the form becomes signed. If is too low, beSigned() throws 
// an exception. The catch block handles that exception and prints the reason using e.what(). This function is const because 
// signing a Form does not modify the Bureaucrat.
void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << "[Bureaucrat] " << this->_name << " signed " << form.getName() << "!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "[Bureaucrat] " << this->_name << " could not sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << " | Grade: " << bureaucrat.getGrade();
	return (out);
}
