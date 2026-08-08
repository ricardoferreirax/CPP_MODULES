/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:30:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/08 17:53:18 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>

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

static void	displayInvalidLiteral(void)
{
	std::cout << "[char]: Invalid literal." << std::endl;
	std::cout << "[int]: Invalid literal." << std::endl;
	std::cout << "[float]: Invalid literal." << std::endl;
	std::cout << "[double]: Invalid literal." << std::endl;
}

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
		std::cout << "[char]: Impossible." << std::endl;
		std::cout << "[int]: Impossible." << std::endl;
		std::cout << "[float]: nanf" << std::endl;
		std::cout << "[double]: nan" << std::endl;
		return (true);
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "[char]: Impossible." << std::endl;
		std::cout << "[int]: Impossible." << std::endl;
		std::cout << "[float]: -inff" << std::endl;
		std::cout << "[double]: -inf" << std::endl;
		return (true);
	}
	if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
	{
		std::cout << "[char]: Impossible." << std::endl;
		std::cout << "[int]: Impossible." << std::endl;
		std::cout << "[float]: +inff" << std::endl;
		std::cout << "[double]: +inf" << std::endl;
		return (true);
	}
	return (false);
}

static void	displayValue(double value, int type)
{
	float number;

	if (type == CHAR)
	{
		std::cout << "[char]: ";
		if (value < 0 || value > 255)
			std::cout << "No char value.";
		else if (!ft_is_printable(static_cast<int>(value)))
			std::cout << "Non displayable.";
		else
			std::cout << "'" << static_cast<char>(value) << "'";
		std::cout << std::endl;
	}
	else if (type == INT)
	{
		std::cout << "[int]: ";
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			std::cout << "No int value.";
		else
			std::cout << static_cast<int>(value);
		std::cout << std::endl;
	}
	else if (type == FLOAT)
	{
		std::cout << "[float]: ";
		if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
			std::cout << "No float value.";
		else
		{
			number = static_cast<float>(value);
			if (number >= std::numeric_limits<int>::min() && number <= std::numeric_limits<int>::max()
				&& number == static_cast<int>(number))
				std::cout << static_cast<int>(number) << ".0f";
			else
				std::cout << number << "f";
		}
		std::cout << std::endl;
	}
	else if (type == DOUBLE)
	{
		std::cout << "[double]: ";
		if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
			std::cout << "No double value.";
		else if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()
			&& value == static_cast<int>(value))
			std::cout << static_cast<int>(value) << ".0";
		else
			std::cout << value;
		std::cout << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	double	value;
	char	*end;

	if (isSpecialLiteral(literal))
		return ;
	if (checkSingleCharacter(literal))
	{
		value = static_cast<double>(literal[0]);
		displayValue(value, CHAR);
		displayValue(value, INT);
		displayValue(value, FLOAT);
		displayValue(value, DOUBLE);
		return ;
	}
	value = std::strtod(literal.c_str(), &end);
	if (end == literal.c_str())
	{
		displayInvalidLiteral();
		return ;
	}
	if (value != value)
	{
		displayInvalidLiteral();
		return ;
	}
	if (*end == 'f' && *(end + 1) == '\0')
	{
		if (literal.find('.') == std::string::npos)
		{
			displayInvalidLiteral();
			return ;
		}
		end++;
	}
	if (*end != '\0')
	{
		displayInvalidLiteral();
		return ;
	}
	displayValue(value, CHAR);
	displayValue(value, INT);
	displayValue(value, FLOAT);
	displayValue(value, DOUBLE);
}
