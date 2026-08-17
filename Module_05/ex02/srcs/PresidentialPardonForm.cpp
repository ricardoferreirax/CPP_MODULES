/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:47:24 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/17 15:37:19 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

#include <iostream>

// Builds a PresidentialPardonForm by first constructing its AForm base part with the fixed grades required by 
// this type of form: sign grade = 25 and execute grade = 5 and the target is initialized as "Default".
// AForm(...) is called in the initializer list because the base class must be constructed before the derived 
// PresidentialPardonForm object is completed.
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon Form", 25, 5), _target("Default")
{
	std::cout << "[Pardon] A presidential pardon request has been created!" << std::endl;
}

// Creates a PresidentialPardonForm for a specific target. target stores the person that will receive the pardon.
PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "[Pardon] A presidential pardon request has been created for " << this->_target << "!" << std::endl;
}

//  Creates a new PresidentialPardonForm from another one. AForm(other) calls the copy constructor of the base class so that the
// AForm part is copied correctly. target is then copied as the state specific to PresidentialPardonForm.
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "[Pardon] Request copied for " << this->_target << "!" << std::endl;
}

// Copies both parts of the derived object: the AForm base part and the target specific to PresidentialPardonForm.
// AForm::operator=(other) -> copies the assignable state inherited from AForm.
// _target = other._target -> copies the state specific to PresidentialPardonForm.
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << "[Pardon] Request data has been assigned!" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "[Pardon] Request for " << this->_target << " has been closed!" << std::endl;
}

//  Returns the target of the Presidential Pardon Form. The target is returned by const reference to avoid copying the string and
// to prevent modification through the returned reference.
const std::string &PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

// Performs the concrete action of a PresidentialPardonForm. This function implements the virtual processForm() operation defined by
// AForm. AForm itself does not know what every form should actually do.
// After AForm::execute() confirms that the form is signed and that the executor has the required grade, it calls: this->processForm();
// Because processForm() is virtual, C++ selects this implementation when the real object is a PresidentialPardonForm.
// This is runtime polymorphism. The concrete action is to announce that the target has been pardoned by Zaphod Beeblebrox.
void PresidentialPardonForm::processForm(void) const
{
	std::cout << "[Pardon] " << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
