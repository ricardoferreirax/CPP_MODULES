/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:20:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/05 18:56:06 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) 
	: AForm("Robotomy Request Form", 72, 45), _target("Default")
{
	std::cout << "[Robotomy] Has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "[Robotomy] Has been created for " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), _target(src._target)
{
	std::cout << "[Robotomy] Request copied for " << this->_target << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
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

void RobotomyRequestForm::performAction(void) const
{
	std::cout << "* Loud drilling and metallic noises *" << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << "[Robotomy] " << this->_target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "[Robotomy] " << this->_target << " failed!" << std::endl;
	}
}
