/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:15:21 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/06 22:59:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl has been created!\n" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "\nHarl has been destroyed!" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]: I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int i;

	std::string levels[4] = 
	{
		"DEBUG", 
		"INFO", 
		"WARNING", 
		"ERROR" 
	};
	void (Harl::*funcs[4])(void) = 
	{ 
		&Harl::debug, 
		&Harl::info, 
		&Harl::warning, 
		&Harl::error 
	};
	if (level.empty())
	{
		std::cout << "No level provided!" << std::endl;
		return ;
	}
	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "Unknown level! Use DEBUG, INFO, WARNING, or ERROR!" << std::endl;
}
