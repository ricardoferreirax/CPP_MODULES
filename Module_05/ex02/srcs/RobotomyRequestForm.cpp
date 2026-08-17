/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:44:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/17 15:37:28 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

// Builds the AForm base class using the fixed requirements of a RobotomyRequestForm: sign grade = 72 and execute grade = 45
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request Form", 72, 45), _target("Default")
{
	std::cout << "[Robotomy] A robotomy request has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "[Robotomy] A robotomy request has been created for " << this->_target << "!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "[Robotomy] Request copied for " << this->_target << "!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << "[Robotomy] Request data has been assigned!" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[Robotomy] " << this->_target << " has been destroyed!" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

// Performs the concrete action of a RobotomyRequestForm. This function implements the virtual processForm() operation 
// declared by AForm. AForm::execute() first checks that the form is signed and that the executor has grade 45 or better.
// std::rand() % 2 produces either 0 or 1, giving two possible outcomes: 0 -> robotomy succeeds or 1 -> robotomy fails.
// The function is an example of runtime polymorphism because AForm::execute() calls processForm() through the AForm interface, 
// while the implementation executed here belongs specifically to RobotomyRequestForm.
void RobotomyRequestForm::processForm(void) const
{
	std::cout << "* Loud drilling and metallic noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << "[Robotomy] " << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "[Robotomy] Robotomy failed on " << this->_target << "!" << std::endl;
}
