/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 17:44:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/07 17:45:53 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy request", 72, 45), _target("Default")
{
	std::cout << "[Robotomy] A request has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("Robotomy request", 72, 45), _target(target)
{
	std::cout << "[Robotomy] A request has been created for " << this->_target << "!" << std::endl;
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
	std::cout << "[Robotomy] Request has been assigned!" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[Robotomy] Request for " << this->_target << " has been destroyed!" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::executeForm(void) const
{
	std::cout << "* Loud drilling and metallic noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << "[Robotomy] " << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "[Robotomy] Robotomy of " << this->_target << " failed!" << std::endl;
}
