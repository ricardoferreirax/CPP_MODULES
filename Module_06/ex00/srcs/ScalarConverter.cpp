/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:30:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/23 20:53:30 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

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

static bool	isValidNumericChar(char c)
{
	return (isDigit(c) || c == '.' || c == '+' || c == '-' || c == 'f' || c == 'e' || c == 'E');
}

static void	printInvalid(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool	printPseudoLiteral(const std::string &literal)
{
	std::string floatValue;
	std::string doubleValue;
	
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
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << floatValue << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
	return (true);
}

bool ScalarConverter::checkSingleCharacter(const std::string &literal)
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
	if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos
		&& literal.find('e') == std::string::npos && literal.find('E') == std::string::npos)
		return (INT);
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
		return (FLOAT);
	return (DOUBLE);
}

static bool	hasValidSyntax(const std::string &literal, int type, char *end)
{
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isValidNumericChar(literal[i]))
			return (false);
		if ((literal[i] == '+' || literal[i] == '-') && i > 0 && literal[i - 1] != 'e' && literal[i - 1] != 'E')
			return (false);
	}
	if (type == FLOAT)
		return (*end == 'f' && *(end + 1) == '\0');
	return (*end == '\0');
}

static std::string formatNumber(double value, int precision)
{
	std::ostringstream stream;
	std::string res;

	if (value != 0.0 && value < 0.000001 && value > -0.000001)
		precision = 10;
	stream << std::fixed << std::setprecision(precision) << value;
	res = stream.str();
	while (res.find('.') != std::string::npos && res[res.length() - 1] == '0')
		res.erase(res.length() - 1);
	if (res[res.length() - 1] == '.')
		res += '0';
	return (res);
}

static void	printChar(char value, bool possible)
{
	std::cout << "char: ";
	if (!possible)
		std::cout << "impossible";
	else if (!isPrintable(static_cast<unsigned char>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << value << "'";
	std::cout << std::endl;
}

static void	printInt(int value, bool possible)
{
	std::cout << "int: ";
	if (!possible)
		std::cout << "impossible";
	else
		std::cout << value;
	std::cout << std::endl;
}

static void	printFloat(float value)
{
	std::cout << "float: " << formatNumber(value, 6) << "f" << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "double: " << formatNumber(value, 15) << std::endl;
}

static void	printOverflow(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: overflow" << std::endl;
	std::cout << "float: overflow" << std::endl;
	std::cout << "double: overflow" << std::endl;
}

static bool	canConvertToInt(double value)
{
	if (value != value)
		return (false);
	if (value < std::numeric_limits<int>::min())
		return (false);
	if (value >= static_cast<double>(std::numeric_limits<int>::max()) + 1.0)
		return (false);
	return (true);
}

static bool	canConvertToChar(double value)
{
	if (value != value)
		return (false);
	if (value < std::numeric_limits<char>::min())
		return (false);
	if (value >= static_cast<double>(std::numeric_limits<char>::max()) + 1.0)
		return (false);
	return (true);
}

static void	convertChar(char value)
{
	printChar(value, true);
	printInt(static_cast<int>(value), true);
	printFloat(static_cast<float>(value));
	printDouble(static_cast<double>(value));
}

static void	convertInt(int value)
{
	if (!canConvertToChar(value))
		printChar(0, false);
	else
		printChar(static_cast<char>(value), true);
	printInt(value, true);
	printFloat(static_cast<float>(value));
	printDouble(static_cast<double>(value));
}

static void	convertFloat(float value)
{
	if (!canConvertToChar(value))
		printChar(0, false);
	else
		printChar(static_cast<char>(value), true);
	if (!canConvertToInt(value))
		std::cout << "int: overflow" << std::endl;
	else
		printInt(static_cast<int>(value), true);
	printFloat(value);
	printDouble(static_cast<double>(value));
}

static void	convertDouble(double value)
{
	if (!canConvertToChar(value))
		printChar(0, false);
	else
		printChar(static_cast<char>(value), true);
	if (!canConvertToInt(value))
		std::cout << "int: overflow" << std::endl;
	else
		printInt(static_cast<int>(value), true);
	if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
		std::cout << "float: overflow" << std::endl;
	else
		printFloat(static_cast<float>(value));
	printDouble(value);
}

void ScalarConverter::convert(const std::string &literal)
{
	char   *end;
	double	value;
	int		type;
	char   *intEnd;
	long	intNbr;
	float	floatNbr;

	if (printPseudoLiteral(literal))
		return ;
	if (checkSingleCharacter(literal))
	{
		convertChar(literal[0]);
		return ;
	}
	type = findLiteralType(literal);
	value = std::strtod(literal.c_str(), &end);
	if (end == literal.c_str() || value != value || !hasValidSyntax(literal, type, end))
	{
		printInvalid();
		return ;
	}
	if (value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity())
	{
		printOverflow();
		return ;
	}
	if (type == INT)
	{
		intNbr = std::strtol(literal.c_str(), &intEnd, 10);
		if (*intEnd == '\0' && intNbr >= std::numeric_limits<int>::min() && intNbr <= std::numeric_limits<int>::max())
			convertInt(static_cast<int>(intNbr));
		else
			convertDouble(value);
	}
	else if (type == FLOAT)
	{
		floatNbr = static_cast<float>(value);
		if (floatNbr == std::numeric_limits<float>::infinity() || floatNbr == -std::numeric_limits<float>::infinity())
			convertDouble(value);
		else
			convertFloat(floatNbr);
	}
	else
		convertDouble(value);
}
