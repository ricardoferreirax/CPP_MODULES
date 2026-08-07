/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:03:01 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/07 20:30:39 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "[ScalarConverter] Default ScalarConverter created!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "[ScalarConverter] ScalarConverter has been destroyed!" << std::endl;
}

static int	ft_is_printable(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

static int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// static int	ft_count_char(const std::string &s, char c)
// {
// 	int	count;

// 	count = 0;
// 	for (size_t i = 0; i < s.size(); i++)
// 	{
// 		if (s[i] == c)
// 			count++;
// 	}
// 	return (count);
// }

bool ScalarConverter::checkSingleCharacter(const std::string &literal)
{
	if (literal.length() != 1)
		return (false);
	if (!ft_is_printable(literal[0]))
		return (false);
	if (ft_is_digit(literal[0]))
		return (false);
	return (true);
}

bool ScalarConverter::isSpecialLiteral(const std::string &str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "[char]: NaN has no char value." << std::endl;
		std::cout << "[int]: NaN has no int value." << std::endl;
		std::cout << "[float]: Not a Number." << std::endl;
		std::cout << "[double]: Not a Number." << std::endl;
		return (true);
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "[char]: No char value." << std::endl;
		std::cout << "[int]: No int value." << std::endl;
		std::cout << "[float]: Negative infinity." << std::endl;
		std::cout << "[double]: Negative infinity." << std::endl;
		return (true);
	}
	if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
	{
		std::cout << "[char]: No char value." << std::endl;
		std::cout << "[int]: No int value." << std::endl;
		std::cout << "[float]: Positive infinity." << std::endl;
		std::cout << "[double]: Positive infinity." << std::endl;
		return (true);
	}
	return (false);
}

void ScalarConverter::convert(const std::string &literal)
{
	if (checkSingleCharacter(literal))
	{
		std::cout << literal << " is a character literal." << std::endl;
		return ;
	}
	if (isSpecialLiteral(literal))
		return ;
	std::cout << literal << " is neither a char nor a pseudo-literal." << std::endl;
}
