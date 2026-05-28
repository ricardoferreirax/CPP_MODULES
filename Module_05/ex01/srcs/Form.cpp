/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:31:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/05/28 23:38:00 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void) : 
	_name("Default"), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
	this->_isSigned = false;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : 
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
	this->_isSigned = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw ;
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw ;
}

Form::Form(const Form &src) : 
	_name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
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
