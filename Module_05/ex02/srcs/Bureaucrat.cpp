/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:40:58 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/17 11:12:39 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

// Creates a Bureaucrat with the default name and grade 150. Grade 150 is the lowest valid rank.
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

// Tries to sign the given AForm using the current Bureaucrat.
//form.beSigned(*this) passes the current Bureaucrat to the form. "*this" means the current Bureaucrat object.
// AForm::beSigned() contains the actual validation rule. It compares the Bureaucrat's grade with the required signing grade.
// If the grade is sufficient, the form becomes signed and this function prints a success message.
// signForm() is const because signing a form changes the AForm, not the Bureaucrat.
void Bureaucrat::signForm(AForm &form) const
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

// Tries to execute the given AForm using the current Bureaucrat. This function does not execute the concrete action directly.
//Instead, it calls: form.execute(*this); AForm::execute() is responsible for checking:
// 1. Whether the form is signed and 2. Whether the Bureaucrat has the required execution grade.
// If both conditions are valid, AForm::execute() calls processForm(). processForm() is virtual, so the implementation that runs 
// depends on the real type of the form:  ShrubberyCreationForm  -> creates the shrubbery file.
//     									  RobotomyRequestForm    -> performs the robotomy attempt.
//     									  PresidentialPardonForm -> prints the presidential pardon.
// This is runtime polymorphism: executeForm() works with an AForm reference, but the concrete behavior is selected according to the actual 
// derived object. If execute() throws an exception, the catch block handles it and prints the reason using e.what()
// This function is const because executing a form does not modify the Bureaucrat itself.
void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << "[Bureaucrat] " << this->_name << " executed " << form.getName() << "!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "[Bureaucrat] " << this->_name << " could not execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

// Allows a Bureaucrat to be printed directly with std::cout.
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << " | Grade: " << bureaucrat.getGrade();
	return (out);
}
