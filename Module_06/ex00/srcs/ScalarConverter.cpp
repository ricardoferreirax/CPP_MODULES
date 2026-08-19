/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:30:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/19 17:49:38 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter(void)
{
	
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
	
}

static bool	isPrintable(int value)
{
	return (value >= 32 && value <= 126);
}

static bool	isDigit(char value)
{
	return (value >= '0' && value <= '9');
}

static void	printInvalid(void)
{
	std::cout << "[char]: invalid literal" << std::endl;
	std::cout << "[int]: invalid literal" << std::endl;
	std::cout << "[float]: invalid literal" << std::endl;
	std::cout << "[double]: invalid literal" << std::endl;
}

static bool	printPseudoLiteral(const std::string &literal)
{
	std::string	floatValue;
	std::string	doubleValue;

	if (literal == "nan" || literal == "nanf")
	{
		floatValue = "nanf";
		doubleValue = "nan";
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		floatValue = "-inff";
		doubleValue = "-inf";
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		floatValue = "+inff";
		doubleValue = "+inf";
	}
	else
		return (false);
	std::cout << "[char]: impossible" << std::endl;
	std::cout << "[int]: impossible" << std::endl;
	std::cout << "[float]: " << floatValue << std::endl;
	std::cout << "[double]: " << doubleValue << std::endl;

	return (true);
}

bool	ScalarConverter::checkSingleCharacter(const std::string &literal)
{
	if (literal.length() != 1)
		return (false);
	if (!isPrintable(literal[0]))
		return (false);
	if (isDigit(literal[0]))
		return (false);
	return (true);
}

static int	findLiteralType(const std::string &literal)
{
	if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos)
		return (INT);
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
		return (FLOAT);
	return (DOUBLE);
}

static bool	hasValidFloatSyntax(const std::string &literal, char *end)
{
	if (literal.find('.') == std::string::npos)
		return (false);
	if (*end != 'f')
		return (false);
	if (*(end + 1) != '\0')
		return (false);
	return (true);
}

static bool	hasValidSyntax(const std::string &literal, int type, char *end)
{
	if (type == FLOAT)
		return (hasValidFloatSyntax(literal, end));
	return (*end == '\0');
}

static void	printChar(double value)
{
	std::cout << "[char]: ";
	if (value < 0 || value > 127)
		std::cout << "impossible";
	else if (!isPrintable(static_cast<int>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
}

static void	printInt(double value)
{
	std::cout << "[int]: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

static bool	isWholeFloat(float value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		return (false);
	return (value == static_cast<int>(value));
}

static bool	isWholeDouble(double value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		return (false);
	return (value == static_cast<int>(value));
}

static void	printFloat(double value)
{
	float	converted;

	std::cout << "[float]: ";
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	converted = static_cast<float>(value);
	if (isWholeFloat(converted))
		std::cout << static_cast<int>(converted) << ".0f";
	else
		std::cout << std::fixed << std::setprecision(1) << converted << "f";
	std::cout << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "[double]: ";
	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isWholeDouble(value))
		std::cout << static_cast<int>(value) << ".0";
	else
		std::cout << std::fixed << std::setprecision(1) << value;
	std::cout << std::endl;
}

static void	printAllConversions(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void	ScalarConverter::convert(const std::string &literal)
{
	double	value;
	char	*end;
	int		type;

	if (printPseudoLiteral(literal))
		return ;
	if (checkSingleCharacter(literal))
	{
		printAllConversions(static_cast<double>(literal[0]));
		return ;
	}
	type = findLiteralType(literal);
	value = std::strtod(literal.c_str(), &end);
	if (end == literal.c_str() || value != value)
	{
		printInvalid();
		return ;
	}
	if (!hasValidSyntax(literal, type, end))
	{
		printInvalid();
		return ;
	}
	printAllConversions(value);
}
