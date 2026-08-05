/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:40:58 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/05 11:01:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Unnamed"), _grade(150)
{
	std::cout << "[Bureaucrat] An default bureaucrat has been created!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "[Bureaucrat] " << this->_name << " has been created with grade " << this->_grade << "!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "[Bureaucrat] Copied " << other._name << " with grade " << other._grade << "!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << "[Bureaucrat] Grade assignment completed." << std::endl;
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

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed \"" << form.getName() << "\"!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->_name << " could not sign \"" << form.getName() << "\": " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " finished executing \"" << form.getName() << "\"!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->_name << " could not execute \"" << form.getName() << "\": " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade 1 is already the highest possible grade!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade 150 is already the lowest possible grade!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << " is currently at grade " << bureaucrat.getGrade();
	return (out);
}
